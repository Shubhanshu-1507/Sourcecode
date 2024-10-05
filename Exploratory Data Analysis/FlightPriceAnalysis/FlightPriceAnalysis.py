# %% [markdown]
# Flight Price Analysis 

# %% [markdown]
# The airline industry is a dynamic and complex ecosystem influenced by various factors, including fuel costs, economic conditions, competition, and consumer demand. Understanding the trends and patterns in flight prices is crucial for both travelers and industry stakeholders. This analysis aims to delve into the dynamics of flight prices, exploring key factors that affect pricing strategies and their implications. 
# 
# By dissecting historical data and employing analytical tools, we aim to uncover insights that can inform both consumers seeking cost-effective travel options and industry professionals strategizing pricing and revenue management. Additionally, this analysis may shed light on emerging trends and potential future developments in the airline pricing landscape.

# %% [markdown]
# Importing Libraries 

# %%
import pandas as pd
import numpy as np 
import matplotlib.pyplot as plt
import seaborn as sns
%matplotlib inline

# %% [markdown]
# Read Files

# %%
trainDS=pd.read_excel('Data_Train.xlsx')
testDS=pd.read_excel('Test_set.xlsx')

# %%
testDS.head()

# %%
trainDS.head()

# %% [markdown]
# Binding both the files together

# %%
finalDS = pd.concat([trainDS, testDS])

# %%
finalDS.head()

# %%
finalDS.tail()

# %%
finalDS.info()

# %% [markdown]
# Making Separate columns for Date, Month and Year

# %%
finalDS['Date']=finalDS['Date_of_Journey'].str.split('/').str[0]
finalDS['Month']=finalDS['Date_of_Journey'].str.split('/').str[1]
finalDS['Year']=finalDS['Date_of_Journey'].str.split('/').str[2]

# %%
finalDS.head()

# %%
finalDS['Date']=finalDS['Date'].astype(int)
finalDS['Month']=finalDS['Month'].astype(int)
finalDS['Year']=finalDS['Year'].astype(int)
finalDS.info()

# %%
finalDS.drop('Date_of_Journey',axis=1, inplace=True)

# %%
finalDS.head()

# %% [markdown]
# Spilting Time into hours and minutes columns

# %%
finalDS['Arrival_Time'] = finalDS["Arrival_Time"].apply(lambda x:x.split(" ")[0])
finalDS.head()

# %%
finalDS['Arrival_Hour']=finalDS['Arrival_Time'].str.split(':').str[0]
finalDS['Arrival_Min']=finalDS['Arrival_Time'].str.split(':').str[1]

finalDS['Arrival_Hour']=finalDS['Arrival_Hour'].astype(int)
finalDS['Arrival_Min']=finalDS['Arrival_Min'].astype(int) 

finalDS.info()

# %%
finalDS['Dep_Hour']=finalDS['Dep_Time'].str.split(':').str[0]
finalDS['Dep_Min']=finalDS['Dep_Time'].str.split(':').str[1]

finalDS['Dep_Hour']=finalDS['Dep_Hour'].astype(int)
finalDS['Dep_Min']=finalDS['Dep_Min'].astype(int) 

finalDS.drop('Dep_Time',axis=1, inplace=True)

finalDS.info()

# %%
finalDS['Total_Stops']=finalDS['Total_Stops'].map({'non-stop':0,'1 stop':1,'2 stops':2,'3 stops':3,'4 stops':4,'nan':1})
finalDS.drop('Route',axis=1,inplace=True)
finalDS.head()

# %%
finalDS['Additional_Info'].unique()
finalDS.info()

# %%
finalDS.drop('Duration',axis=1,inplace=True)

# %%
finalDS.head()

# %%
finalDS['Airline'].unique()

# %%
from sklearn.preprocessing import LabelEncoder
labelencoder=LabelEncoder()

# %%
finalDS['Airline']=labelencoder.fit_transform(finalDS['Airline'])
finalDS['Source']=labelencoder.fit_transform(finalDS['Source'])
finalDS['Destination']=labelencoder.fit_transform(finalDS['Destination'])
finalDS['Additional_Info']=labelencoder.fit_transform(finalDS['Additional_Info'])
finalDS.shape

# %%
finalDS.head()

# %%
finalDS[['Airline']]

# %%
pd.get_dummies(finalDS,columns=["Airline", "Source", "Destination"] ,drop_first = True)

# %%



