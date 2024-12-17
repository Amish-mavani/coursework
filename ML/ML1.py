from bs4 import BeautifulSoup
import requests
import csv
import pandas as pd
import numpy as np


def get_title(soup):
    try:
        # Outer Tag Object
        title_string = soup.find("h1", {'class':'pt4 pb4 oh mb4 fs36 lh40 auto_height'}).text.strip()
    except AttributeError:
        title_string = ""
    return title_string
 
def get_genre(soup):
    try:
      genre_string = soup.find("div", {'class':'m-tags'}).text.strip()
    except AttributeError:
        genre_string = ""
    return genre_string


def get_Synopsis(soup):
    try:
      Synopsis_string = soup.find("div", {'class':'g_txt_over mb48 fs16 j_synopsis _txtover'}).text.strip()
    except AttributeError:
        Synopsis_string = ""
    return Synopsis_string


def get_rating(soup):
    try:
        rating = soup.find("p", {'class':'fl g_star_num fs22'}).text.strip()
    except AttributeError:
        try:
            rating = soup.find("small ", {'class':'l'}).text.strip()
        except:
            rating = ""
    return rating


def get_review(soup):
    try:
      review_string = soup.find("h3", {'class':'fl g_h2 fs24 lh32 fw700 pl1 ell mr24'}).text.strip()
    except AttributeError:
        review_string = ""
    return review_string


if __name__ == '__main__':
    # add your user agent
    HEADERS = ({'User-Agent':'', 'Accept-Language': 'en-US, en;q=0.5'})
    # The webpage URL
    URL = "https://www.webnovel.com/ranking/novel/bi_annual/power_rank?timeType=3&sourceType=2&signStatus=1"
    # HTTP Request
    webpage = requests.get(URL, headers=HEADERS)
    # Soup Object containing all data
    soup = BeautifulSoup(webpage.content, "html.parser")
    # Fetch links as List of Tag Objects
    links = soup.find_all("a", attrs={'class':'c_l'})
    # Store the links
    links_list = []
    webnovel_df = pd.DataFrame()
   
    # Loop for extracting links from Tag Objects
    for link in links:
            links_list.append(link.get('href'))
    d = {"title":[], "genre":[], "Synopsis":[], "rating":[], "review":[]}
   
    # Loop for extracting details from each link
    for link in links_list:
        new_webpage = requests.get("https://www.webnovel.com" + link, headers=HEADERS)
        new_soup = BeautifulSoup(new_webpage.content, "html.parser")
       
        # Function calls to display all necessary product information
        d['title'].append(get_title(new_soup))
        d['genre'].append(get_genre(new_soup))
        d['Synopsis'].append(get_Synopsis(new_soup))
        d['rating'].append(get_rating(new_soup))
        d['review'].append(get_review(new_soup))


    webnovel_df = pd.DataFrame.from_dict(d)
    webnovel_df['title'].replace('', np.nan, inplace=True)
    webnovel_df = webnovel_df.dropna(subset=['title'])
    webnovel_df.to_csv("webnovel_data.csv", header=True, index=False)


df = pd.read_csv('webnovel_data.csv')
print(df)
