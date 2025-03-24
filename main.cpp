#include <iostream>
#include <string>
#include <curl/curl.h>
#include <nlohmann/json.hpp>

using namespace std;
using json = nlohmann::json;

static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    size_t totalSize = size * nmemb;
    string* response = static_cast<string*>(userp);
    response->append(static_cast<char*>(contents), totalSize);
    return totalSize;
}

string fetchPage(const string& url) {
    CURL* curl = curl_easy_init();
    string buffer;

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_USERAGENT, "curl-example");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &buffer);
        curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }

    return buffer;
}

void fetchAllVideos(const string& apiKey, const string& playlistId) {
    string nextPageToken;
    int page = 1;

    do {
        string url = "https://www.googleapis.com/youtube/v3/playlistItems?part=snippet&maxResults=50&playlistId=" +
                     playlistId + "&key=" + apiKey;

        if (!nextPageToken.empty()) {
            url += "&pageToken=" + nextPageToken;
        }

        cout << "\n🌐 Fetching page " << page++ << "...\n";

        string response = fetchPage(url);
        json data = json::parse(response);

        for (const auto& item : data["items"]) {
            cout << "🎵 " << item["snippet"]["title"] << endl;
        }

        nextPageToken = data.value("nextPageToken", "");

    } while (!nextPageToken.empty());
}
int main() {
    string apiKey, playlistId;
    cout << "Enter API key: ";
    cin >> apiKey;
    cout << "Enter Playlist ID: ";
    cin >> playlistId;

    fetchAllVideos(apiKey, playlistId);
}
