#ifndef H_ZipCode
#define H_ZipCode

#include <fstream>
#include <vector>

class ZipCode {
      public:
              std::string toString();
              bool operator<(const ZipCode & other);
              void toMap(std::string file, std::map<int, ZipCode> m);

              //Method to tokenize the date from the file
              std::vector< std::vector< std::string> >  getTokens(std::string filename);
              int id;
              //5 digit Zipcode or military postal code(FPO/APO)
              std::string zipCode;
              //Standard, PO BOX Only, Unique, Military(implies APO or FPO)
              std::string zipCodeType;
              //USPS offical city name(s)
              std::string city;
              //USPS offical state, territory, or quasi-state (AA, AE, AP)
              std::string state;
              //Primary, Acceptable,Not Acceptable
              std::string locationType;
              //Decimal Latitude, if available
              std::string lat;
              //Decimal Longitude, if available
              std::string lon;
              //Standard Display (eg Phoenix, AZ)
              std::string location;
              //If Primary location, Yes implies historical Zipcode
              //No Implies current Zipcode
              //If not Primary, Yes implies Historical Placename
              std::string decommissioned;
              //Number of Individual Tax Returns Filed in 2008
              long taxReturnsFiled;
              //Tax returns filed + Married filing jointly + Dependents
              long estimatedPopulation;
              //Total of Wages Salaries and Tips
              long totalWages;
};
#endif
