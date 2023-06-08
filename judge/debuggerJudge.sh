./generate.out $@
x=0
while [ $x -le $2 ]
do
    sed -n '1,'$x'p' tests.txt > tmp.txt
    ./output.out < tmp.txt > output.txt
    ./futballFantasy.out < tmp.txt > your_output0.txt
    x=`expr $x - 1`
    sed -n '1,'$x'p' tests.txt > tmp.txt
    ./output.out < tmp.txt > your_output.txt
    ./futballFantasy.out < tmp.txt > your_output1.txt
    i=$(sed -n '$=' your_output0.txt)
    j=$(sed -n '$=' your_output1.txt)
    i=`expr $i`
    j=`expr $j + 1`
    sed -n $j','$i'p' your_output0.txt >> your_output.txt
    x=`expr $x + 2`
    if cmp --silent -- "output.txt" "your_output.txt"; then
        :
    else
        echo `expr $x - 1`
    fi
done
rm tmp.txt
./Judge.sh $@