import pandas as pd
import numpy as np
from datetime import date
import seaborn as sns
 
# Load the dataset
df = pd.read_csv('cars_data.csv')
df.head() # first 4 sample
df.shape  # number of observations and features
df.dtypes # data types
df.info()
 
# Check for Duplication
df.nunique()
#df[df.duplicated()]
 
# Missing Values Calculation
df.isna().sum() # missing values per feature
#df.isna().sum().sum() # number of missing cells
#round(df.isna().sum().sum() / df.size * 100, 1) # percentage of missing cells
 
# Replace null values
df.replace(np.nan,'0',inplace = True)
 
# Filter df
# df[df['Seats']==5].head()
 
# Data Reduction
df = df.drop(['S.No.'],axis=1)
df.info()
 
# Feature Engineering
 
# Creating Features
date.today().year
df['Car_Age']=date.today().year-df['Year']
df['Brand'] = df.Name.str.split().str.get(0)
df['Model'] = df.Name.str.split().str.get(1) + df.Name.str.split().str.get(2)
df[['Name','Brand','Model']]
df.head()
 
# Data Cleaning/Wrangling
print(df.Brand.unique())
print(df.Brand.nunique())
 
searchfor = ['Isuzu' ,'ISUZU','Mini','Land']
df[df.Brand.str.contains('|'.join(searchfor))].head(5)
 
df["Brand"].replace({"ISUZU": "Isuzu", "Mini": "Mini Cooper","Land":"Land Rover"}, inplace=True)
 
# Statistics Summary (Count, Mean, Standard Deviation, median, mode, minimum value, maximum value, range, standard deviation)
df.describe().T
df.describe(include='all').T
 
# separate Numerical and categorical variables for easy analysis
cat_cols=df.select_dtypes(include=['object']).columns
num_cols = df.select_dtypes(include=np.number).columns.tolist()
print("Categorical Variables:")
print(cat_cols)
print("Numerical Variables:")
print(num_cols)
 
#8. Analyzing/visualizing the dataset by taking one variable at a time
for col in num_cols:
    print(col)
    print('Skew :', round(df[col].skew(), 2))
    plt.figure(figsize = (15, 4))
    plt.subplot(1, 2, 1)
    df[col].hist(grid=False)
    plt.ylabel('count')
    plt.subplot(1, 2, 2)
    sns.boxplot(x=df[col])
    plt.show()
 
fig, axes = plt.subplots(3, 2, figsize = (18, 18))
fig.suptitle('Bar plot for all categorical variables in the dataset')
sns.countplot(ax = axes[0, 0], x = 'Fuel_Type', data = df, color = 'blue',
              order = df['Fuel_Type'].value_counts().index);
sns.countplot(ax = axes[0, 1], x = 'Transmission', data = df, color = 'blue',
              order = df['Transmission'].value_counts().index);
sns.countplot(ax = axes[1, 0], x = 'Owner_Type', data = df, color = 'blue',
              order = df['Owner_Type'].value_counts().index);
sns.countplot(ax = axes[1, 1], x = 'Location', data = df, color = 'blue',
              order = df['Location'].value_counts().index);
sns.countplot(ax = axes[2, 0], x = 'Brand', data = df, color = 'blue',
              order = df['Brand'].head(20).value_counts().index);
sns.countplot(ax = axes[2, 1], x = 'Model', data = df, color = 'blue',
              order = df['Model'].head(20).value_counts().index);
axes[1][1].tick_params(labelrotation=45);
axes[2][0].tick_params(labelrotation=90);
axes[2][1].tick_params(labelrotation=90);
 
# Data Transformation
# Function for log transformation of the column
def log_transform(df,col):
    for colname in col:
        if (df[colname] == 1.0).all():
            df[colname + '_log'] = np.log(df[colname]+1)
        else:
            df[colname + '_log'] = np.log(df[colname])
    df.info()
log_transform(df,['Kilometers_Driven','Price'])
#Log transformation of the feature 'Kilometers_Driven'
sns.distplot(df["Kilometers_Driven_log"], axlabel="Kilometers_Driven_log");

