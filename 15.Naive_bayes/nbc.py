

#import required modules
import csv
from collections import Counter
#open dataset file
f = open('datastr.csv', 'rb')
query={'Age':'middle_age','Qualification':'MTech.','Experience':'medium','Work Type':'?'}
# you can also try to predict other attribute as follows
#query={'Age':'middle_age','Qualification':'?','Experience':'medium','Work Type':'Service'}

print '-----------------------------------------------'
print 'Query tuple:',query
print '-----------------------------------------------'
reader = csv.reader(f)
headers = reader.next()
#-----------------------------------------------
#declare datastructures
column = {}
freq = {}
Probability={}
occurance_counts={}
conditionaloccurance={}
condProb={}
FinalResults={}
Init_total=1.0
#-----------------------------------------------
#Function for calculating conditional probabilities:
def condProbfun(queryattribute_val,classlabel):
	value=0.0
	counter=0.0
	occure=0.0
	result=0.0
	f = open('datastr.csv', 'rb')
	reader = csv.reader(f)
	for row in reader:
		if queryattribute_val in row and classlabel in row:
			value= value+1
	occure=occurance_counts[classlabel]
	result=value/occure
	return result
#-----------------------------------------------



for h in headers:
	column[h] = []
for row in reader:
	for h, v in zip(headers, row):
		column[h].append(v)
#print column.keys()
for h in headers:
	word_list = column[h]
	# Get a set of unique words from the list
	word_set = set(word_list)
	# create frequency dictionary
	
	for word in word_set:
	    occurance_counts[word]=word_list.count(word)  #Get occurance count
	    freq[word] = word_list.count(word) / float(len(word_list)) #Get frequency count
	    Probability[word]=freq[word] #prior probability

print freq
#-----------------------------------------------
for name,item in query.items(): #which class
        if item == '?':
                classname=name
print '-----------------------------------------------'                
print 'To Predict:',classname
print '-----------------------------------------------'
#-----------------------------------------------
#word_list = column[classname]
word_set = set(word_list)

for word in word_set:
	classlabel=word # {Consultancy,Service,Research}
	total=Init_total
	for queryattribute in query:
		if not queryattribute == classname:
			queryattribute_val=query[queryattribute] 
			#Get Every other attribute than classlabel print query[queryattribute]
			ans=condProbfun(queryattribute_val,classlabel)
			print 'conditional probility P(',queryattribute_val ,'|',classlabel,')=',ans
			total=total*ans
			condProb[classlabel]=total
	#print 'Total', total
	print 'Prior probability of' ,classname,':',classlabel,'=',freq[classlabel]		
	TotalProbability=total*freq[classlabel]	
	FinalResults[classlabel]=TotalProbability
	print '-----------------------------------------------'
	print 'Multiplication of above probabilities to give Posterior Probability of ',classname,':',classlabel,'=',FinalResults[classlabel]
	print '-----------------------------------------------'
list=FinalResults.values()
#print 'FinalResults:',FinalResults
#-----------------------------------------------
#Predict Classname
maxprob=max(list)
for name,item in FinalResults.items():
        if item == maxprob:
                classpredicted=name
print '*********************************************************'
print 'Predicted Class (Highest posterior Probability )for given query tuple is:', classpredicted
print '*********************************************************'
#-----------------------------------------------

'''
Output:
ubuntu@ubuntu:~$ python nbc.py
-----------------------------------------------
Query tuple: {'Age': 'middle_age', 'Work Type': 'Service', 'Experience': 'medium', 'Qualification': '?'}
-----------------------------------------------
{'Work Type': 0.09090909090909091, 'Consultancy': 0.2727272727272727, 'Service': 0.2727272727272727, 'Research': 0.36363636363636365}
-----------------------------------------------
To Predict: Qualification
-----------------------------------------------
conditional probility P( middle_age | Work Type )= 0.0
conditional probility P( Service | Work Type )= 0.0
conditional probility P( medium | Work Type )= 0.0
Prior probability of Qualification : Work Type = 0.0909090909091
-----------------------------------------------
Multiplication of above probabilities to give Posterior Probability of  Qualification : Work Type = 0.0
-----------------------------------------------
conditional probility P( middle_age | Service )= 0.333333333333
conditional probility P( Service | Service )= 1.0
conditional probility P( medium | Service )= 0.666666666667
Prior probability of Qualification : Service = 0.272727272727
-----------------------------------------------
Multiplication of above probabilities to give Posterior Probability of  Qualification : Service = 0.0606060606061
-----------------------------------------------
conditional probility P( middle_age | Consultancy )= 0.666666666667
conditional probility P( Service | Consultancy )= 0.0
conditional probility P( medium | Consultancy )= 0.333333333333
Prior probability of Qualification : Consultancy = 0.272727272727
-----------------------------------------------
Multiplication of above probabilities to give Posterior Probability of  Qualification : Consultancy = 0.0
-----------------------------------------------
conditional probility P( middle_age | Research )= 0.5
conditional probility P( Service | Research )= 0.0
conditional probility P( medium | Research )= 0.75
Prior probability of Qualification : Research = 0.363636363636
-----------------------------------------------
Multiplication of above probabilities to give Posterior Probability of  Qualification : Research = 0.0
-----------------------------------------------
*********************************************************
Predicted Class (Highest posterior Probability )for given query tuple is: Service
*********************************************************
ubuntu@ubuntu:~$ 
'''


































