import json
import os
import requests
from dotenv import load_dotenv

load_dotenv

api = os.getenv("APIKEY")
city = input("Enter the city name")

params = {
        'q' : city,
        "appid_id":api,
        "units":"metric"}

baseurl = "url"


response = requests.get("url",params=params)
print(f"status>{response.status_code}")
data = response.json()

print(json.dumps(data,indent=2))
#we see the data and get what we want and then print it
