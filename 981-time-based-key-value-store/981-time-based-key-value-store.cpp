class TimeMap
{
    public:
        unordered_map<string, unordered_map<int, string>> time;
    TimeMap() {}

    void set(string key, string value, int timestamp)
    {
        time[key][timestamp] = value;
    }

    string get(string key, int timestamp)
    {
        

        for (int t = timestamp; t >= 1; --t)
        {
            if(time[key].find(t) != time[key].end())
                return time[key][t];
        }
        return "";
    }

};

/**
 *Your TimeMap object will be instantiated and called as such:
 *TimeMap* obj = new TimeMap();
 *obj->set(key,value,timestamp);
 *string param_2 = obj->get(key,timestamp);
 */