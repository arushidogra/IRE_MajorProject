'''
Program : POS tagger for hindi language based on HMM (Hidden Markov Model)
Author : Utsav Chokshi
Version : 1.0
Coding standard : PEP0008
Reference : http://airccj.org/CSCP/vol3/csit3639.pdf
'''

# -*- coding: utf-8 -*-
import math

from nltk.corpus import indian

def train_hmm_pos_tagger():

	#Consider tagged hindi sentences of NLTK as training data.
	train_data = indian.tagged_sents('hindi.pos')

	#Define dictionary for each database
	word_tag_dict = {}
	tag_freq_dict = {}
	tag_tag_dict = {}

	tag_freq_dict['<S>'] = len(train_data)
	tag_freq_dict['</S>'] = len(train_data)

	#Calculate frequency count for each database
	for sentence in train_data:
		prev_tag = '<S>'
		for word_tag_pair in sentence:
			if word_tag_pair not in word_tag_dict:
				word_tag_dict[word_tag_pair] = 1
			else:
				word_tag_dict[word_tag_pair] += 1
			
			current_tag = word_tag_pair[1]
			if current_tag not in tag_freq_dict:
				tag_freq_dict[current_tag] = 1
			else:
				tag_freq_dict[current_tag] += 1

			tag_tag_pair = (prev_tag,current_tag)
			if tag_tag_pair not in tag_tag_dict:
				tag_tag_dict[tag_tag_pair] = 1
			else:
				tag_tag_dict[tag_tag_pair] += 1

			prev_tag = current_tag

		current_tag = '</S>'
		tag_tag_pair = (prev_tag,current_tag)
		if tag_tag_pair not in tag_tag_dict:
			tag_tag_dict[tag_tag_pair] = 1
		else:
			tag_tag_dict[tag_tag_pair] += 1


	test_data = indian.tagged_sents('hindi.pos')
	sentence = test_data[0]

	prev_tag = '<S>'
	for pair in sentence:
		word = pair[0]
	 	max_prob = -100000000000000
	 	for current_tag in tag_freq_dict.keys():
	 		word_tag_pair = (word,current_tag)
	 		if word_tag_pair not in word_tag_dict:
	 			word_tag_prob = math.log(1.0/tag_freq_dict[current_tag])
	 		else:
	 			word_tag_prob = math.log(float(word_tag_dict[word_tag_pair])/float(tag_freq_dict[current_tag]))

	 		prev_cur_tag_pair = (prev_tag,current_tag)
	 		if prev_cur_tag_pair not in tag_tag_dict:
	 			prev_cur_tag_prob = math.log(1.0/tag_freq_dict[prev_tag])
	 		else:
	 			prev_cur_tag_prob = math.log(float(tag_tag_dict[prev_cur_tag_pair])/float(tag_freq_dict[prev_tag]))

	 		max_freq = 1.0	
	 		for future_tag in tag_freq_dict.keys():
	 			cur_future_tag_pair = (current_tag,future_tag)
	 			if cur_future_tag_pair in tag_tag_dict:
	 				if tag_tag_dict[cur_future_tag_pair] > max_freq:
	 					max_freq = tag_tag_dict[cur_future_tag_pair]
	 		
	 		cur_future_tag_prob = math.log(float(max_freq)/float(tag_freq_dict[current_tag]))
	 		total_prob = word_tag_prob + prev_cur_tag_prob + cur_future_tag_prob
			
			if total_prob > max_prob:
				max_prob = total_prob
				tag_assigned = current_tag

		prev_tag = tag_assigned

		print word
		print "Original tag : ",
		print pair[1]
		print "Tag assigned : ",
		print tag_assigned	


if __name__ == '__main__':
    train_hmm_pos_tagger()