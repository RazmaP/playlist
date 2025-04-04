# YouTube to Spotify Playlist Sync (C++ + Python)

This project is a two-part tool that makes it simple to convert a YouTube playlist into a Spotify playlist. The C++ component fetches video titles from a YouTube playlist using the YouTube Data API, and the Python component uses Spotify's Web API to create and populate a corresponding playlist on your Spotify account.

## Overview

Ever wanted to seamlessly transfer your favorite YouTube playlist to Spotify? This project does just that by splitting the task into two parts:

1. **YouTube Playlist Fetcher (C++):**  
   Connects to the YouTube Data API, retrieves video titles, parses them using JSON, and writes the results to a file.

2. **Spotify Playlist Creator (Python):**  
   Reads the file of song names, authenticates with Spotify using OAuth, searches for the songs on Spotify, creates a new playlist, and adds the matching tracks. Any songs that aren’t found are logged for review.

---

## Technologies Used

- **C++**  
  - `libcurl` for making HTTP requests to the YouTube Data API  
  - `nlohmann/json` for JSON parsing

- **Python**  
  - `spotipy` for Spotify Web API integration and OAuth authentication


### Part 1: C++ – Fetch YouTube Playlist
- **API Integration:**  
  Uses the YouTube Data API v3 to fetch details from a public YouTube playlist.
- **JSON Parsing:**  
  Extracts video titles from the JSON response.
- **Output File:**  
  Writes the video titles (one per line) to `playlist.txt`.
  
### Part 2: Python – Create Spotify Playlist
- **OAuth Authentication:**  
  Uses a manual OAuth flow suitable for Jupyter notebooks and standalone scripts.
- **Playlist Sync:**  
  Reads `playlist.txt`, searches for each song on Spotify, and creates a new playlist with all found tracks.
- **Error Logging:**  
  Logs any songs that couldn’t be found in `not_found.txt`.


#### For the YouTube Part (C++)

- A **YouTube Data API key** (available from the [Google Cloud Console](https://console.cloud.google.com/))
- The ID of the public YouTube playlist you want to sync

#### For the Spotify Part (Python)

- A **Spotify Developer Account** to create an app and obtain your **Client ID** and **Client Secret**
- Python 3 installed along with the `spotipy` library (`pip install spotipy`)

### Instructions

#### Running the C++ Program

1. Open `main.cpp` in your preferred IDE or text editor.
2. Compile the program ensuring that you link against `libcurl` and include the `nlohmann/json` header.
3. Run the executable.
4. When prompted, enter your YouTube Data API key and the playlist ID.
5. The program will fetch the video titles and save them in `playlist.txt`.

#### Running the Python Script

1. Open the Python script (or Jupyter notebook) that handles Spotify integration.
2. Update the script with your Spotify Client ID and Client Secret.
3. Run the script.
4. After authenticating via OAuth, paste the redirect URL as prompted.
5. The script will create a new Spotify playlist, add all found tracks, and log any unfound songs in `not_found.txt`.

---


- **main.cpp**  
  The C++ source file that connects to the YouTube Data API and writes video titles to `playlist.txt`.

- **playlist.txt**  
  A text file generated by the C++ program containing all the fetched song names (one per line).

- **spotify_sync.py**  
  The Python script that reads `playlist.txt`, authenticates with Spotify, creates a playlist, and adds the tracks.

- **not_found.txt**  
  A log file listing any songs that couldn’t be found on Spotify.

## Contributing

Contributions are welcome! If you have suggestions or improvements, please open an issue or submit a pull request.

---

## Contact

For any questions or issues, please open an issue on GitHub or contact the project maintainer.

---

Enjoy syncing your favorite playlists from YouTube to Spotify!
