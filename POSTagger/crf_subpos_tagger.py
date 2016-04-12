'''
Program : CRF Based Sub-POS Tagger 
Author : Utsav Chokshi
Version : 1.0
Coding standard : PEP0008
'''

'''
Input file format (On each line):

Word1 POS-Tag
Word2 POS-Tag
.
WordN POS-Tag
<Empy Line Before starting new sentence>
'''

'''
Output file format (On each line):

Word1 POS-Tag Predicted-SubPOS-Tag
Word2 POS-Tag Predicted-SubPOS-Tag
Word3 POS-Tag Predicted-SubPOS-Tag
.
.
WordN POS-Tag Predicted-SubPOS-Tag
<Empy Line Before starting new sentence>
'''

# -*- coding: utf-8 -*-
import sys
import time
import os

#Asks for user input
print "Make sure CRF++ is installed."
model_file_name = raw_input("Enter model file name : ")
test_file_name = raw_input("Enter test file name : ")

#Prepare command to execute
current_time_stamp = str(int(round(time.time()*1000)))
output_file_name = current_time_stamp + "_output.txt"
"crf_test -m model_v2_complete_data hindi-annotated-bio_test.txt > op1.txt"
command = "crf_test -m " + model_file_name + " "  + test_file_name + " > " + output_file_name

#Run the command
print "crf_test is running. Wait for a while..."
os.system(command)
print "Output file has been created." 
