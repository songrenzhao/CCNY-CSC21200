#include "stats.h"
#include <assert.h>
using namespace std;
namespace main_Zhao
{
    statistician::statistician()
    {
        count = 0;
        total = 0;
    }
    void statistician::next(double r)
    {
        count++;
        total+= r;

        if(count == 1)
        {
            tinyest = r;
            largest = r;
        }
        else
        {
            if(r < tinyest)         tinyest = r;
            else if(r > largest)    largest = r;
        }

    }
    void statistician::reset()
    {
        count = 0;
        total = 0;
    }

    int statistician::length() const    {return count;}
    double statistician::sum() const    {return total;}
    double statistician::mean() const
    {
        assert(length() > 0);
        return total/count;
    }
    double statistician::minimum() const
    {
        assert(length() > 0);
        return tinyest;
    }
    double statistician::maximum() const
    {
        assert(length() > 0);
        return largest;
    }
    main_Zhao::statistician operator + (const statistician& s1, const statistician& s2)
    {
        statistician newStat;
        if(s1.length() == 0) return s2;
        if(s2.length() == 0) return s1;
        newStat.count = s1.length() + s2.length();
        newStat.total = s1.sum() + s2.sum();
        if(s1.minimum() < s2.minimum())
            newStat.tinyest = s1.minimum();
        else
            newStat.tinyest = s2.minimum();

        if(s1.maximum() > s2.maximum())
            newStat.largest = s1.maximum();
        else
            newStat.largest = s2.maximum();
        return newStat;
    }
    statistician operator * (double scale, const statistician& s)
    {
        statistician newStat;
        if(s.length() == 0)
            return s;

        newStat.count = s.length();
        newStat.total = s.length() * s.mean() * scale;
        double small = s.minimum() * scale;
        double large = s.maximum() * scale;
        if(small < large)
        {
            newStat.tinyest = small;
            newStat.largest = large;
        }
        else
        {
            newStat.tinyest = large;
            newStat.largest = small;
        }
        return newStat;
    }
    bool operator ==(const statistician& s1, const statistician& s2)
    {
        if(s1.length() != s2.length())
            return false;
        if(s1.length() == 0 && s2.length() == 0)
            return true;
        return ((s1.mean() == s2.mean())
                           &&
                (s1.sum() == s2.sum())
                           &&
                (s1.minimum() == s2.minimum())
                           &&
                (s1.maximum() == s2.maximum()));
    }
}

