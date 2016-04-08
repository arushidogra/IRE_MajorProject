#1600 400
import json

train = open("train_data.dat","w")
test = open("test_data.dat","w")


filename = open("../hi.data","r")
start = 0

while True:
    line = filename.readline()
    if line == '' or start>2000:
        break
    if start < 1600:
        train.write(line)
    elif start < 2000:
        test.write(line)
    start = start + 1
filename.close()
train.close()
test.close()
