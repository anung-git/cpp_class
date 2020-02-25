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

unsigned char Alarm::getAlarm(unsigned char jam,unsigned char menit){
    int compare = (jam*60) + menit;
    unsigned char status;
    switch (compare){
        case Alarm::suruq:
            // status=
            break;
        
        case Alarm::imsya:
            // status=
            break;
        
        case Alarm::subuh:
            // status=
            break;
        
        case Alarm::dzuhur:
            // status=
            break;
        
        case Alarm::ashar:
            // status=
            break;
        
        case Alarm::maghrib:
            // status=
            break;
        case Alarm::isya:
            // status=
            break;
        
        default:
            break;
    }
}
void Alarm::setSubuh(unsigned char jam,unsigned char menit){
    Alarm::subuh = (jam*60) + menit;
}
void Alarm::setDzuhur(unsigned char jam,unsigned char menit){
    Alarm::dzuhur = (jam*60) + menit;
}
void Alarm::setAshar(unsigned char jam,unsigned char menit){
    Alarm::ashar = (jam*60) + menit;
}
void Alarm::setMaghrib(unsigned char jam,unsigned char menit){
    Alarm::maghrib = (jam*60) + menit;
}
void Alarm::setIsya(unsigned char jam,unsigned char menit){
    Alarm::isya = (jam*60) + menit;
}
void Alarm::setImsya(unsigned char jam,unsigned char menit){
    Alarm::imsya = (jam*60) + menit;
}

Alarm::Alarm(/* args */)
{
}

Alarm::~Alarm()
{
}
