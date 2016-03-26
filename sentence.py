import os
import sys
'''
Sentence breaker
'''
if __name__ == "__main__":
    if len(sys.argv) < 3:
        sys.stderr.write("Usage: " + sys.argv[0] + " <corpusfile>" + " <outputfile>\n")
        sys.exit(2)
    input_file = sys.argv[1]
    output_file = sys.argv[2]
    command = "ind-tokz --i " +  input_file + " --o " +  output_file + " --l hin"
    os.system(command)


