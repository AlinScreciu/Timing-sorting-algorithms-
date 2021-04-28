# Timing-sorting-algorithms-
# IMPORTANT:<br>The program times the algorithms on arrays with up to 1 million elements, as such the time for the final result is about 2 hours, this depends on your machine.

## A simple C++ 14 progam that times sorting algorithms on different types on data.<br>The dataset was generated using a python script, located in the /dataset folder.
## The results are saved into a times.csv file in the following way:
```
sort name,data type,size,time
Merge Sort,Almost sorted,50,0.000019
Quick Sort,Almost sorted,50,0.000002
Bubble Sort,Almost sorted,50,0.000002
Insertion Sort,Almost sorted,50,0.000000
Selection Sort,Almost sorted,50,0.000002
Heap Sort,Almost sorted,50,0.000002
Radix Sort,Almost sorted,50,0.000003
```
## TODO:
- [ ] Limit the size of the data so it gives the results faster;
- [ ] Make python plotter better;
