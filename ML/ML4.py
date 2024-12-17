
import string
import re
import csv
import pandas as pd
import nltk
!pip install emoji
!pip install googletrans==3.1.0a0.
import emoji
import googletrans
from googletrans import Translator
from nltk.corpus import stopwords
from nltk.tokenize import word_tokenize
from nltk.stem.porter import PorterStemmer
from nltk.stem import WordNetLemmatizer
nltk.download('punkt')
nltk.download('stopwords')
nltk.download('wordnet')
 
df = pd.read_csv('dhoniretires_tweets.csv')
 
#Lower Casing
df['user_name1'] = df['user_name'].str.lower()
 
#remove is_retweet
df.drop(['is_retweet'], axis=1)
 
#Punctuation Mark Removal
df['text2'] = df['text'].str.replace('[^a-zA-Z0-9]+',' ')
 
#Tokenization
df['text3'] = df['text2'].str.split()
 
df['text4']=df['text2'].apply(lambda X: word_tokenize(X))
 
#Stop Word Removal
def remove_stopwords(text):
  stop_words = set(stopwords.words("english"))
  word_tokens = word_tokenize(text)
  text = [word for word in word_tokens if word not in stop_words]
  return text
 
df['text5']=df['text2'].apply(remove_stopwords)
 
#Stemming
ps = PorterStemmer()
def stem_words(text):
  word_tokens = word_tokenize(text)
  stems = [ps.stem(word) for word in word_tokens]
  return stems
 
#def stem_words(text):
#   porter = PorterStemmer()
#    result=[]
#    for word in text:
#        result.append(porter.stem(word))
#    return result
 
df['text6']=df['text'].apply(stem_words)
 
#Lemmatization
wl = WordNetLemmatizer()
def lemm_word(text):
  word_tokens = word_tokenize(text)
  lemm_text = [wl.lemmatize(word) for word in word_tokens]
  return lemm_text
 
df['text7']=df['text'].apply(lambda x:lemm_word(x))
 
#Translation
print(googletrans.LANGUAGES)
tr = Translator()
def trans(text):
  result = tr.translate(text, dest = 'hi')
  return result
df['text8']=df['text'].apply(trans)
 
#Emoji to text
def etot(emoji_text):
    text_with_aliases = emoji.demojize(emoji_text)
    return text_with_aliases
 
df['text9']=df['text'].apply(etot)
 
def joint(text):
  result=[]
  for word in text:
    result.append(' '.join(text))
    return result
df['text10']=df['text7'].apply(joint)
print(df)
