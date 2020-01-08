# Quicksort

## Execution Results (5 times)
### Leftmost: Longer First
* 0.020697 sec
* 0.017637 sec
* 0.016567 sec
* 0.023542 sec
* 0.022772 sec
* Avg = 0.020243 sec

### Leftmost: Shorter First
* 0.019363 sec
* 0.016033 sec
* 0.016587 sec
* 0.023341 sec
* 0.019777 sec
* Avg = 0.019020 sec

### Leftmost: Original
* 0.017035 sec
* 0.015894 sec
* 0.016568 sec
* 0.022167 sec
* 0.019083 sec
* Avg = 0.018149 sec

### Median of three: Longer First
* 0.018141 sec
* 0.017572 sec
* 0.015753 sec
* 0.021215 sec
* 0.018579 sec
* Avg = 0.018252 sec

### Median of three: Shorter First
* 0.017640 sec
* 0.016201 sec
* 0.015500 sec
* 0.021212 sec
* 0.018995 sec
* Avg = 0.017910 sec

### Median of three: Original
* 0.016774 sec
* 0.015973 sec
* 0.016004 sec
* 0.022527 sec
* 0.018265 sec
* Avg = 0.017909 sec

## Speed
Median-Original > Median-Shorter-First > Leftmost-Original <br>> Median-Longer-First > Leftmost-Shorter-First > Leftmost-Longer-First

## Conclusion
On average, median-of-three is faster than leftmost. By analyzing longer-first, shorter-first and original, we can conclude that the best one is "original", which means that the execution time will have the best result if the length of left sublist is equal to that of right sublist. From the conclusion mentioned, taking the median of three makes the length of left sublist closer to the length of right sublist, which will result in a better result than leftmost.