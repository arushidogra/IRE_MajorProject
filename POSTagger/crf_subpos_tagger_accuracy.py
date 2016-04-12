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

#Open output file for reading
file_desc = open(output_file_name,"r")

#Read all lines
all_lines = file_desc.readlines()
true_classsified = 0.0
total_classified = 0.0

#Calculate accuracy
for line in all_lines:
    if line != '\n':
        column_values = line.strip().split("\t")
        last_column = len(column_values)
        if column_values[last_column-1] == column_values[last_column-2]:
            true_classsified += 1
        total_classified += 1

accuracy = float(true_classsified/total_classified)*100

print "Accuracy is : " + str(accuracy)