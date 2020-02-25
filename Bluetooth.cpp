class Bluetooth
{
private:
    /* data */
public:
    Bluetooth(/* args */);
    void setHC05();
    void setUniBT()
    ~Bluetooth();
};

void Bluetooth::setHC05()
{
    Serial1.begin(38400);
}
void Bluetooth::setUniBT()
{
    Serial1.begin(38400);
}

Bluetooth::Bluetooth(/* args */)
{
    
}

Bluetooth::~Bluetooth()
{
}
