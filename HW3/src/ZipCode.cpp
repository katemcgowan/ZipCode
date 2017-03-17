#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include "ZipCode.h"

std::vector< std::vector< std::string> >  ZipCode::getTokens(std::string filename){
	std::vector< std::vector< std::string > > zipCodes;
	std::string line;
	std::ifstream fin(filename, std::ifstream::in);
	while(std::getline(fin, line)){
		// Use a trash string to ignore some chars
		std::string trash;
		// Create a StringStream from which to
		// consume the string
		std::istringstream ss(line);
		// ID
		std::string id;
		std::getline(ss, id, ',');
		// Zip code
		std::string zip;
		std::getline(ss, trash, '"');
		std::getline(ss, zip, '"');
		// Zip code type
		std::string type;
		std::getline(ss, trash, ',');
		std::getline(ss, trash, '"');
		std::getline(ss, type, '"');
		// City
		std::string city;
		std::getline(ss, trash, ',');
		std::getline(ss, trash, '"');
		std::getline(ss, city, '"');
		// State
		std::string state;
		std::getline(ss, trash, ',');
		std::getline(ss, trash, '"');
		std::getline(ss, state, '"');
		// Location Type
		std::string location_type;
		std::getline(ss, trash, ',');
		std::getline(ss, trash, '"');
		std::getline(ss, location_type, '"');
		// Latitude
		std::string lat;
		std::getline(ss, trash, ',');
		std::getline(ss, lat, ',');
		// Long
		std::string lng;
		std::getline(ss, trash, ',');
		std::getline(ss, lng, ',');
		// Skip x-axis, y-axis, and z-axis
		std::getline(ss, trash, ',');
		std::getline(ss, trash, ',');
		std::getline(ss, trash, ',');
		// World Region
		std::string region;
		std::getline(ss, trash, ',');
		std::getline(ss, trash, '"');
		std::getline(ss, region, '"');
		// Country
		std::string country;
		std::getline(ss, trash, ',');
		std::getline(ss, trash, '"');
		std::getline(ss, country, '"');
		// Location Text
		std::string loc_text;
		std::getline(ss, trash, ',');
		std::getline(ss, trash, '"');
		std::getline(ss, loc_text, '"');
		// Location
		std::string location;
		std::getline(ss, trash, ',');
		std::getline(ss, trash, '"');
		std::getline(ss, location, '"');
		// Decommissioned
		std::string decommissioned;
		std::getline(ss, trash, ',');
		std::getline(ss, trash, '"');
		std::getline(ss, decommissioned, '"');

		std::vector< std::string > temp;
		temp.push_back(id);
		temp.push_back(zip);
		temp.push_back(type);
		temp.push_back(city);
		temp.push_back(state);
		temp.push_back(loc_text);
		temp.push_back(location);
		temp.push_back(lng);
		temp.push_back(lat);
		temp.push_back(decommissioned);
		zipCodes.push_back(temp);
	}

	return zipCodes;
}

std::string ZipCode::toString() {

	return "Results for Zip Code: " + zipCode + '\n' +
	"Zip Code Type: " + zipCodeType + '\n' +  "City: " + city +
	 '\n' + "State: " + state + '\n' + "Location: " + location +
	 "Location Type: " + locationType + '\n' + "Latitude: " + lat +
	 '\n' + "Longitude: " + lon + '\n' + "Decommissioned: " +
	 decommissioned;
}

bool ZipCode::operator<(const ZipCode & other) {
	return this->zipCode < other.zipCode;
}

void ZipCode::toMap(std::string file, std::map<int, ZipCode> m) {
	std::vector< std::vector< std::string > > zips = ZipCode::getTokens(file);
	 for (unsigned int i = 0; i < zips.size(); i++) {
		 ZipCode z;
		 z.id = std::stoi(zips[i][0]);
		 z.zipCode = zips[i][1];
		 z.zipCodeType = zips[i][2];
		 z.city = zips[i][3];
		 z.state = zips[i][4];
		 z.locationType = zips[i][5];
		 z.location = zips[i][6];
		 z.lon = zips[i][7];
		 z.lat = zips[i][8];
		 z.decommissioned = zips[i][9];

		 m[z.id] = z;
	 	 	 }
}


int main(int argc, char** argv) {
	ZipCode z;
	std::map<int, ZipCode> zMap;
	z.toMap("zip-codes.csv", zMap);
  //if (argc != 2) {
  //  std::cout << "Please Enter a Zip Code: " << std::endl;
  //}

	//std::string input;
	//std::cin >> input;

	for (auto it : zMap) {
		std::cout << it.second.zipCode <<  std::endl;

		//if (it.second.zipCode == input) {
		//std::cout << it.second.toString() << std::endl;
		//}
	}
}
