import matplotlib.pyplot as plt 
import csv
from matplotlib.font_manager import FontProperties
sizes = []   
plt.figure(dpi=300)
a = 10
l=[5,10]
while( a < 100001):
    for x in l:
        sizes.append(x*a)
    a*=10

sorts={}
with open("times.csv") as f:
    d = csv.DictReader(f)
    for row in d:
        if(row["data type"]=="Random sorted"):
            sorts.setdefault(row["sort name"],[]);
            sorts[row["sort name"]].append(float(row["time"]))
h=[]
sorts["Bubble Sort"] = sorts["Bubble Sort"][:3]
sorts["Selection Sort"] = sorts["Selection Sort"][:3]
sorts["Insertion Sort"] = sorts["Insertion Sort"][:3]
for x in sorts:
   t, = plt.plot(sizes[:len(sorts[x])],sorts[x][:],label = x) 
   h.append(t)

plt.ylabel("Seconds")
plt.xlabel("Number of elements")
fontP = FontProperties()        
fontP.set_size('medium')
plt.legend(handles=h,title="Random sorted", bbox_to_anchor=(1.05, 1), loc='upper left', prop=fontP)

