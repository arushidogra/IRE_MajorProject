#this program adds nwe line marker after the end of sentence marker '<.>'.
$/ = " <.>";
while(<STDIN>)
{
print $_,"\n";
}
