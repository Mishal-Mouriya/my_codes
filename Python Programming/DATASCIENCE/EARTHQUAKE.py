from pathlib import Path
import json
import plotly.express as px

# === Step 1: Load the GeoJSON file ===
path = Path(r"D:\heavens feel\PYTHON RESOURCES\3rd edition resources\pcc_3e-main\chapter_16\mapping_global_datasets\eq_data\eq_data_1_day_m1.geojson")
contents = path.read_text(encoding="utf-8")
geojson_data = json.loads(contents)  # -> geojson_data is a dict

# Top-level structure:
# geojson_data = {
#     'type': 'FeatureCollection',
#     'metadata': {...},
#     'features': [ {...}, {...}, ... ],   # <== LIST of earthquake entries
#     'bbox': [...]
# }

# === Step 2: Extract earthquake details ===
titles, mags, lats, lons = [], [], [], []

for feature in geojson_data["features"]:  # Each feature is a dict


        # Structure of each `feature`:
        # {
        #     'type': 'Feature',
        #     'properties': {           # <-- metadata about the quake
        #         'mag': 1.2,
        #         'place': '10km S of Town',
        #         'time': 1680000000,
        #         'title': 'M 1.2 - 10km S of Town'
        #     },
        #     'geometry': {             # <-- location info
        #         'type': 'Point',
        #         'coordinates': [lon, lat, depth]
        #     },
        #     'id': 'abc123'
        # }

    properties = feature["properties"]      # Dictionary under 'properties'
    geometry = feature["geometry"]          # Dictionary under 'geometry'

    mag = properties.get("mag", 0)          # feature["properties"]["mag"]
    title = properties.get("title", "No Title")  # feature["properties"]["title"]

    lon, lat, *_ = geometry["coordinates"]  # feature["geometry"]["coordinates"] = [lon, lat, depth]

    # Append to lists
    mags.append(mag)
    titles.append(title)
    lats.append(lat)
    lons.append(lon)

# === Step 3: Plot using Plotly on a global map ===
fig = px.scatter_geo(
    lat=lats,                      # y-axis (latitude)
    lon=lons,                      # x-axis (longitude)
    text=titles,                   # Hover text
    size=mags,                     # Size of dots = magnitude
    color=mags,                    # Color = magnitude
    color_continuous_scale="Viridis",
    title="Global Earthquake Map (1-Day M1+ Events)",
    projection="natural earth"
)

# === Step 4: Save and view the plot ===
fig.write_html("earthquake_global_map.html")
print("✅ Earthquake map saved as 'earthquake_global_map.html'")


import webbrowser
webbrowser.open("earthquake_global_map.html")

