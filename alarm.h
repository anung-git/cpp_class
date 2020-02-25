class Alarm
{
private:
    /* data */
    int subuh,dzuhur,ashar,maghrib,isya,imsya,suruq;
public:
    Alarm(/* args */);
    ~Alarm();
    unsigned char getAlarm(unsigned char jam , unsigned char menit);
    void setSubuh(unsigned char jam , unsigned char menit);
    void setDzuhur(unsigned char jam , unsigned char menit);
    void setAshar(unsigned char jam , unsigned char menit);
    void setMaghrib(unsigned char jam , unsigned char menit);
    void setIsya(unsigned char jam , unsigned char menit);
    void setImsya(unsigned char jam , unsigned char menit);
    
};