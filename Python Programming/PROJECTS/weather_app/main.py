import requests         # lets us make HTTP requests to the internet
import json             # lets us pretty-print the JSON response for inspection
import os               # lets us read environment variables
from dotenv import load_dotenv   # reads our .env file into the environment

load_dotenv()           # MUST be called first — loads .env into memory

API_KEY = os.getenv("API_KEY")   # reads the key from .env, not hardcoded in code
BASE_URL = "https://api.openweathermap.org/data/2.5/weather"

city = input("Enter a city name: ")   # collect what the user wants

params = {
    "q": city,           # the city name
    "appid": API_KEY,    # authenticate with your key
    "units": "metric"    # return Celsius, not Kelvin
}

# requests builds the full URL automatically from BASE_URL + params
# then sends a GET request to the OpenWeatherMap server
response = requests.get(BASE_URL, params=params)

print("Status code:", response.status_code)
# Print this FIRST — 200 means success, anything else means a problem

data = response.json()
# converts the JSON text response into a real Python dictionary

print(json.dumps(data, indent=2))
# pretty-prints the entire response so you can see its exact structure
# once you understand the structure, you'll start extracting specific values

# Extract individual values from the dictionary you now understand:
temp        = data["main"]["temp"]
humidity    = data["main"]["humidity"]
description = data["weather"][0]["description"]
city_name   = data["name"]

print(f"{city_name}: {temp}°C | Humidity: {humidity}% | {description}")
# Output: Chennai: 31.2°C | Humidity: 73% | few clouds