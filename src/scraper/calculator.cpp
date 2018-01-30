#include "calculator.h"

#include <math.h>


double scraper::calc_RAC(double avg_credits, double avg_time)
{
   unsigned long credit_half_life = 86400 * 7;
   double now = time(0);
   double diff = now - avg_time;
   double weight = exp(-diff * M_LN2/credit_half_life);
   avg_credits *= weight;
   return avg_credits;
}
