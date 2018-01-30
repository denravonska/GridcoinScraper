#include "processor.h"
#include "calculator.h"
#include "model/researcher.h"

#include <boost/property_tree/xml_parser.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/iostreams/filtering_stream.hpp>
#include <boost/iostreams/copy.hpp>
#include <boost/iostreams/filter/gzip.hpp>

#include <iostream>

void scraper::extract_credits(
      const std::string& file,
      const std::set<std::string>& cpid_list)
{
   // GZIP input stream
   std::ifstream input_file(file, std::ios_base::in | std::ios_base::binary);
   boost::iostreams::filtering_istream in;
   in.push(boost::iostreams::gzip_decompressor());
   in.push(input_file);

   // Read XML from GZIP stream
   using boost::property_tree::ptree;
   ptree pt;
   read_xml(in, pt);

   // Process user nodes
   for(const ptree::value_type& v : pt.get_child("users"))
   {
      if(v.first != "user")
         continue;

      // Ensure that user is in CPID list.
      const std::string& cpid = v.second.get<std::string>("cpid");
      auto entry = std::find(cpid_list.begin(), cpid_list.end(), cpid);
      if(entry == cpid_list.end())
      {
         std::cout << "Ignoring " << cpid << std::endl;
         continue;
      }

      // Extract credits.
      double total_credit = v.second.get<double>("total_credit");
      double avg_credit = v.second.get<double>("expavg_credit");
      double avg_time = v.second.get<double>("expavg_time");
      std::cout << "Credits for " << cpid << " " << std::fixed << total_credit << std::endl;
      std::cout << "Average Credits for " << cpid << " " << std::fixed << avg_credit << std::endl;
      double RAC = calc_RAC(avg_credit,avg_time);
      std::cout << "RAC for " << cpid << " " << std::fixed << RAC << std::endl;
   }
}
