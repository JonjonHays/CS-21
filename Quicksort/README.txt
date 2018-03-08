**HOARE PARTITION IMPLEMENTED—ENTER ANY (ARBITRARY) SINGLE 
COMMAND LINE ARGUMENT TO RUN HOARE PARTITION QUICKSORT**


**QUICKSORT TIME STATS ANALYSIS**
---------------------------------


Testing for most efficient threshold constant for using MO3 pivot:
(all testing for MO3 pivot done using Lomuto partition using a
sample size of n = 100k)

Random integers from 0-999 Million (Virtually no duplicates):

c=1;
real	0m0.731s
user	0m0.512s
sys	0m0.079s

c=2;
real	0m0.727s
user	0m0.502s
sys	0m0.082s

c=3;
real	0m0.710s
user	0m0.495s
sys	0m0.080s

c=4;
real	0m0.709s
user	0m0.494s
sys	0m0.079s

c=5;
real	0m0.744s
user	0m0.534s
sys	0m0.079s

c=10;
real	0m0.718s
user	0m0.493s
sys	0m0.080s

c=100;
real	0m0.754s
user	0m0.522s
sys	0m0.081s

c=1000;
real	0m0.811s
user	0m0.576s
sys	0m0.079s

Randomized integers from 0-50 (Lots of duplicates):

c=1;
real	0m1.856s
user	0m1.625s
sys	0m0.086s

c=2;
real	0m1.914s
user	0m1.672s
sys	0m0.082s

c=3;
real	0m1.859s
user	0m1.638s
sys	0m0.081s

c=4;
real	0m1.903s
user	0m1.668s
sys	0m0.081s

c=5;
real	0m1.866s
user	0m1.685s
sys	0m0.079s

c=10;
real	0m1.914s
user	0m1.695s
sys	0m0.079s

c=100;
real	0m1.910s
user	0m1.677s
sys	0m0.080s

c=1000;
real	0m1.994s
user	0m1.772s
sys	0m0.082s

Sorted integers from 0-999 (virtually no duplicates):

c=1;
real	0m0.951s
user	0m0.649s
sys	0m0.299s

c=2;
real	0m0.713s
user	0m0.499s
sys	0m0.208s

c=3;
real	0m0.726s
user	0m0.502s
sys	0m0.219s

c=4;
real	0m0.703s
user	0m0.491s
sys	0m0.206s

c=5;
real	0m0.703s
user	0m0.495s
sys	0m0.204s

c=6;
real	0m0.699s
user	0m0.489s
sys	0m0.205s

c=7;
real	0m0.707s
user	0m0.498s
sys	0m0.204s

c=10;
real	0m0.725s
user	0m0.504s
sys	0m0.217s

c=100;
real	0m0.772s
user	0m0.546s
sys	0m0.221s


Sorted integers from 0-50 (Lots of duplicates):

c=1;
real	0m2.043s
user	0m1.797s
sys	0m0.243s

c=2;
real	0m2.063s
user	0m1.781s
sys	0m0.278s

c=3;
real	0m1.853s
user	0m1.627s
sys	0m0.220s

c=4;
real	0m1.909s
user	0m1.687s
sys	0m0.217s

c=5;
real	0m1.896s
user	0m1.672s
sys	0m0.219s

c=6;
real	0m1.900s
user	0m1.668s
sys	0m0.227s

c=7;
real	0m1.836s
user	0m1.624s
sys	0m0.209s

c=10;
real	0m1.893s
user	0m1.678s
sys	0m0.212s

c=100;
real	0m2.477s
user	0m2.233s
sys	0m0.238s



RESULT: 3,4 and 5 seem to be the most common recurrences of the 
optimal value in the four test cases; so, I’ll take the average of those
three and use c=4.
—————————————————————————————————————————————————————————————————————————





TESTING LOMUTO PARTITION:
------------------------

Randomized integers from 0-999 Million (virtually no duplicates):

n=10k;
real	0m0.080s
user	0m0.053s
sys	0m0.012s

n=100k;
real	0m0.737s
user	0m0.511s
sys	0m0.082s

n=1M;
real	0m7.198s
user	0m5.065s
sys	0m0.762s

n=10M;
real	1m12.536s
user	0m51.922s
sys	0m7.558s

n=100M;
real	12m40.923s
user	9m14.628s
sys	1m16.947s

RESULT: O(n)

-------------------------

Randomized integers from 0-50 (Lots of duplicates):

n=10k;
real	0m0.109s
user	0m0.076s
sys	0m0.027s

n=100k;
real	0m1.911s
user	0m1.667s
sys	0m0.233s

n=1M;
real	2m10.396s
user	2m8.137s
sys	0m2.201s

n=10M;


RESULT: O(nlgn)
——————————————————————————————


Sorted integers from 0-999 Million (Virtually no duplicates);

n=10k;
real	0m0.093s
user	0m0.057s
sys	0m0.033s

n=100k;
real	0m0.714s
user	0m0.499s
sys	0m0.210s

n=1M;
real	0m7.907s
user	0m5.481s
sys	0m2.406s

n=10M;
real	1m9.358s
user	0m48.835s
sys	0m20.483s

RESULT: O(n)
———————————————————————————



Sorted integers from 0-50 (Lots of duplicates):

n=10k;
real	0m0.112s
user	0m0.076s
sys	0m0.034s

n=100k;
real	0m1.919s
user	0m1.685s
sys	0m0.229s

n=1M;
real	2m2.183s
user	1m59.960s
sys	0m2.200s



RESULT:  O(nlgn)
———————————————————————————



TESTING HOARE PARTITION:
————————————————————————

Randomized integers from 0-999 Million (Virtually no duplicates):

n=10k;
real	0m0.091s
user	0m0.058s
sys	0m0.029s

n=100k;
real	0m0.717s
user	0m0.507s
sys	0m0.205s

n=1M;
real	0m7.438s
user	0m5.241s
sys	0m2.158s

n=10M;
real	1m14.263s
user	0m52.723s
sys	0m21.472s

RESULT: O(n)
——————————————————————————


Randomized integers from 0-50 (Lots of duplicates):

n=10k;
real	0m0.093s
user	0m0.062s
sys	0m0.029s

n=100k;
real	0m0.832s
user	0m0.594s
sys	0m0.237s

n=1M;
real	0m6.890s
user	0m4.824s
sys	0m2.048s

n=10M;
real	1m13.865s
user	0m51.413s
sys	0m22.383s

RESULT: O(n) (even faster than O(n)!)
——————————————————————————————————————


Sorted integers from 0-999 Million (Virtually no duplicates):

n=10k;
real	0m0.088s
user	0m0.056s
sys	0m0.029s

n=100k;
real	0m0.722s
user	0m0.502s
sys	0m0.215s

n=1M;
real	0m7.235s
user	0m5.046s
sys	0m2.170s

n=10M;
real	1m9.491s
user	0m48.734s
sys	0m20.717s

RESULT: O(n)
———————————————————————————————————————


Sorted integers from 0-50 (Lots of duplicates):

n=10k;
real	0m0.083s
user	0m0.051s
sys	0m0.030s

n=100k;
real	0m0.738s
user	0m0.505s
sys	0m0.224s

n=1M;
real	0m7.595s
user	0m5.159s
sys	0m2.418s

n=10M;
real	1m11.924s
user	0m50.732s
sys	0m21.143s

RESULT: O(n)
———————————————————————————————————————


**Hoare partition maintained O(n) time through all tests! 
Lomuto began to break down to O(nlgn) time when large amounts 
of duplicates needed to be sorted--the effect of running pre-sorted
data sets through both partitioning schemes was suprisingly subtle**
