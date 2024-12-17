import re
import csv
import nltk
import string
import numpy as np
import pandas as pd
from sklearn import svm
from nltk.corpus import stopwords
from nltk.stem import WordNetLemmatizer
from nltk.tokenize import word_tokenize
from nltk.stem.porter import PorterStemmer
from sklearn.model_selection import train_test_split
from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn.feature_extraction.text import CountVectorizer
from sklearn.linear_model import LogisticRegression
from sklearn.metrics import accuracy_score,confusion_matrix,classification_report
nltk.download('punkt')
nltk.download('stopwords')
nltk.download('wordnet')
 
df = pd.read_csv('spam.csv', encoding='latin-1')
 
#df.shape[0]
doc0 = df['v2'].copy()
doce = doc0.head(5)
doc = doce.transpose()
print(doc)
 
vec=TfidfVectorizer(stop_words='english')
matrix = vec.fit_transform(doc)
print(" Names :",vec.get_feature_names_out())
print("td-idf :",matrix.shape,"n",matrix.toarray())
 
df.head()
df['v1'].value_counts()
x = df['v1']
y = df["v2"]
x_train, x_test,y_train, y_test = train_test_split(x,y,test_size = 0.2)
cv = CountVectorizer()
#cv.fit(y_train)
#y_train = cv.transform(y_train)
#y_test = cv.transform(y_test)
#type(y_train)
features = cv.fit_transform(x_train)
model = LogisticRegression()
model.fit(features,y_train)
predicted = cv.transform(x_test)
score = model.score(predicted,y_test)
print('Accuracy Score: \n', (100*score))
 
##################################
 
df['a'] = df['v2'].str.lower()
 
x = df['v1']
y = df['a']
x_train, x_test,y_train, y_test = train_test_split(x,y,test_size = 0.2)
cv = CountVectorizer()
features = cv.fit_transform(x_train)
model = LogisticRegression()
model.fit(features,y_train)
predicted = cv.transform(x_test)
score = model.score(predicted,y_test)
print('Accuracy Score: \n', (100*score))
 
##################################
 
df['a2'] = df['a'].str.replace('[^a-zA-Z0-9]+',' ')
 
x = df['v1']
y = df['a2']
x_train, x_test,y_train, y_test = train_test_split(x,y,test_size = 0.2)
cv = CountVectorizer()
features = cv.fit_transform(x_train)
model = LogisticRegression()
model.fit(features,y_train)
predicted = cv.transform(x_test)
score = model.score(predicted,y_test)
print('Accuracy Score: \n', (100*score))

