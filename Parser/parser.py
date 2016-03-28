'''
Program : Parsing JSON formatted data file
Author : Utsav Chokshi
Version : 1.0
Coding standard : PEP0008
'''

# -*- coding: utf-8 -*-
import json
import sys


def parse():

    #Check for command line inputs
    file_name = ""
    if len(sys.argv) == 1:
        file_name = 'hi.data'
    else:
        file_name = sys.argv[1]

    #Open file
    try:
        ip_file_desc = open(file_name,'r')
    except IOError:
        print 'Cannot open file : ', file_name

    #Fill output files with data
    op_file_desc_dict = {}
    lines = ip_file_desc.readlines()
    for l in lines:
        data = json.loads(l.strip())
        for key in data.keys():
            #Create output files with same name as key names
            if key not in op_file_desc_dict:
                op_file_desc = open(key+'.data','w')
                op_file_desc_dict[key] = op_file_desc
            if type(data[key]) == list or type(data[key]) == dict:
                op_file_desc_dict[key].write(str(data[key])+'\n')
            else:       
                op_file_desc_dict[key].write(data[key].encode('utf-8')+'\n')

    #Close all files
    ip_file_desc.close()
    for key in op_file_desc_dict.keys():
        op_file_desc_dict[key].close()


if __name__ == '__main__':
    parse()    