./generate.out $@
./futballFantasy.out < tests.txt > your_output.txt
./output.out < tests.txt > output.txt
code --diff your_output.txt output.txt
