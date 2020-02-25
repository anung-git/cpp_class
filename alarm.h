class Alarm
{
private:
    /* data */
    unsigned char jam,menit;
    int subuh,dzuhur,ashar,maghrib,isya,imsya,suruq;
public:
    Alarm(unsigned char &jam,unsigned char &menit);
    ~Alarm();
    unsigned char getAlarm();
    void setSubuh(unsigned char jam , unsigned char menit);
    void setDzuhur(unsigned char jam , unsigned char menit);
    void setAshar(unsigned char jam , unsigned char menit);
    void setMaghrib(unsigned char jam , unsigned char menit);
    void setIsya(unsigned char jam , unsigned char menit);
    void setImsya(unsigned char jam , unsigned char menit);
    
};