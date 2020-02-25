

unsigned char Alarm::getAlarm(){
    int compare = (Alarm::jam*60) + Alarm::menit;
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
    return staus;
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

Alarm::Alarm(unsigned char &jam,unsigned char &menit)
{
}

Alarm::~Alarm()
{
}
