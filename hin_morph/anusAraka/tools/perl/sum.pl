$Distinct_wrds = $ARGV[0];
$Total_wrds = $ARGV[1];
$sum_flag =0;
$freq_flag =0;
if($ARGV[2] eq "n") { $freq_flag=1;}
if($ARGV[2] eq "t") { $sum_flag = 1;}
if($freq_flag == 1) { $min_freq = $ARGV[3];}
if($sum_flag == 1) { $max_total = $ARGV[3]*$Total_wrds/100;}
$total_freq=0;
$total_count=0;
$unkn_total_freq=0;
$unkn_total_count=0;
$in=<STDIN>;
$in =~ /^([0-9]*) (.*)/;
$freq = $1;
$tag = $2;
while(($freq_flag && ($freq > $min_freq)) || ($sum_flag && ($total_freq < $max_total)))
{
$total_freq+=$freq;
$total_count++;
if($tag eq "UN") {
$unkn_total_freq+=$freq;
$unkn_total_count++;
}
if($in=<STDIN>)
{
$in =~ /^([0-9]*) (.*)/;
$freq = $1;
$tag = $2;
}
else {last;}
}
print sprintf("%5d\t\t%5.2f\t\t%7d\t\t%5.2f\t\t%3d\t\t%5.2f\n",$total_count,$total_count*100/$Distinct_wrds,$total_freq,$total_freq*100/$Total_wrds,$unkn_total_count,$unkn_total_freq*100/$Total_wrds);
