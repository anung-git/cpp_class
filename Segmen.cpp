#include "Segmen.h"
#include <avr/pgmspace.h>
#include <Arduino.h>

Segmen::Segmen(const int data, const int sck, const int strobe ){
        pinMode(data,OUTPUT);
        pinMode(sck,OUTPUT);
        pinMode(strobe,OUTPUT);
        Segmen::data = data;
        Segmen::sck = sck;
        Segmen::strobe = strobe;
        Segmen::alarm = 0;

        for(unsigned char i=0;i<4;i++)Segmen::buffer[i]=dataJam[0];
        for(unsigned char i=4;i<12;i++)Segmen::buffer[i]=dataKalender[0];
        for(unsigned char i=12;i<36;i++)Segmen::buffer[i]=dataJadwal[0];


}
unsigned char Segmen::bagiSepuluh( unsigned char nilai ){
  return (nilai/10);
}
unsigned char Segmen::sisaBagiSepuluh( unsigned char nilai ){
  return (nilai%10);
}
void Segmen::setTime(unsigned char jam, unsigned char menit ){
    Segmen::buffer[0] = (Segmen::dataJam[bagiSepuluh(jam)]);
    Segmen::buffer[1] = (Segmen::dataJam[sisaBagiSepuluh(jam)]);
    Segmen::buffer[2] = (Segmen::dataJam[bagiSepuluh(menit)]);
    Segmen::buffer[3] = (Segmen::dataJam[sisaBagiSepuluh(menit)]);
}

void Segmen::setHari(unsigned char hari ){
  if(hari == 0xaa)hari = 28;
  for(unsigned char i = 0;i<8;i++ ){
    Segmen::buffer[i+4]  =  pgm_read_byte_near(lookupKalender+((hari-1)*8)+i);
  }
}

void Segmen::setTanggal(unsigned char tanggal, unsigned char bulan, int tahun ){
    Segmen::buffer[4] = (Segmen::dataKalender[bagiSepuluh( tanggal)]);
    Segmen::buffer[5] = (Segmen::dataKalender[sisaBagiSepuluh( tanggal)]);
    Segmen::buffer[6] = 255-128;
    Segmen::buffer[7] = (Segmen::dataKalender[bagiSepuluh( bulan)]);
    Segmen::buffer[8] = (Segmen::dataKalender[sisaBagiSepuluh( bulan)]);
    Segmen::buffer[9] = 255-128;
    Segmen::buffer[10] = (Segmen::dataKalender[bagiSepuluh( tahun-2000)]);
    Segmen::buffer[11] = (Segmen::dataKalender[sisaBagiSepuluh( tahun-2000)]);
}

void Segmen::setImsya(unsigned char jam, unsigned char menit ){
    Segmen::buffer[12] = (Segmen::dataJam[bagiSepuluh( jam)]);
    Segmen::buffer[13] = (Segmen::dataJam[sisaBagiSepuluh( jam)]);
    Segmen::buffer[14] = (Segmen::dataJam[bagiSepuluh( menit)]);
    Segmen::buffer[15] = (Segmen::dataJam[sisaBagiSepuluh( menit)]);
}
void Segmen::setSubuh(unsigned char jam, unsigned char menit ){
    Segmen::buffer[16] = (Segmen::dataJam[bagiSepuluh( jam)]);
    Segmen::buffer[17] = (Segmen::dataJam[sisaBagiSepuluh( jam)]);
    Segmen::buffer[18] = (Segmen::dataJam[bagiSepuluh( menit)]);
    Segmen::buffer[19] = (Segmen::dataJam[sisaBagiSepuluh( menit)]);
}
void Segmen::setSuruq(unsigned char jam, unsigned char menit ){
    Segmen::buffer[16] = (Segmen::dataJam[bagiSepuluh( jam)]);
    Segmen::buffer[17] = (Segmen::dataJam[sisaBagiSepuluh( jam)]);
    Segmen::buffer[18] = (Segmen::dataJam[bagiSepuluh( menit)]);
    Segmen::buffer[19] = (Segmen::dataJam[sisaBagiSepuluh( menit)]);
}
void Segmen::setDzuhur(unsigned char jam, unsigned char menit ){
    Segmen::buffer[20] = (Segmen::dataJam[bagiSepuluh( jam)]);
    Segmen::buffer[21] = (Segmen::dataJam[sisaBagiSepuluh( jam)]);
    Segmen::buffer[22] = (Segmen::dataJam[bagiSepuluh( menit)]);
    Segmen::buffer[23] = (Segmen::dataJam[sisaBagiSepuluh( menit)]);
}
void Segmen::setAshar(unsigned char jam, unsigned char menit ){
    Segmen::buffer[24] = (Segmen::dataJam[bagiSepuluh( jam)]);
    Segmen::buffer[25] = (Segmen::dataJam[sisaBagiSepuluh( jam)]);
    Segmen::buffer[26] = (Segmen::dataJam[bagiSepuluh( menit)]);
    Segmen::buffer[27] = (Segmen::dataJam[sisaBagiSepuluh( menit)]);
}
void Segmen::setMaghrib(unsigned char jam, unsigned char menit ){
    Segmen::buffer[28] = (Segmen::dataJam[bagiSepuluh( jam)]);
    Segmen::buffer[29] = (Segmen::dataJam[sisaBagiSepuluh( jam)]);
    Segmen::buffer[30] = (Segmen::dataJam[bagiSepuluh( menit)]);
    Segmen::buffer[31] = (Segmen::dataJam[sisaBagiSepuluh( menit)]);
}

void Segmen::setIsya(unsigned char jam, unsigned char menit ){
    Segmen::buffer[32] = (Segmen::dataJam[bagiSepuluh( jam)]);
    Segmen::buffer[33] = (Segmen::dataJam[sisaBagiSepuluh( jam)]);
    Segmen::buffer[34] = (Segmen::dataJam[bagiSepuluh( menit)]);
    Segmen::buffer[35] = (Segmen::dataJam[sisaBagiSepuluh( menit)]);
}

void Segmen::displayNormal(){
    Segmen::alarm = Segmen::modeNormal;
}
void Segmen::displayImsya(){
    Segmen::alarm = Segmen::modeImsya;
    Segmen::setHari(Segmen::kalenderImsya);
}
void Segmen::displaySubuh(){
    Segmen::alarm = Segmen::modeSubuh;
    Segmen::setHari(Segmen::kalenderSubuh);
}
void Segmen::displayDzuhur(){
    Segmen::alarm = Segmen::modeDzuhur;
    Segmen::setHari(Segmen::kalenderDzuhur);
}
void Segmen::displayAshar(){
    Segmen::alarm = Segmen::modeAshar;
    Segmen::setHari(Segmen::kalenderAshar);
}
void Segmen::displayMaghrib(){
    Segmen::alarm = Segmen::modeMaghrib;
    Segmen::setHari(Segmen::kalenderMagrib);
}
void Segmen::displayIsya(){
    Segmen::alarm = Segmen::modeIsya;
    Segmen::setHari(Segmen::kalenderIsya);
}
void Segmen::displayJamOff(){
  Segmen::alarm = Segmen::modeJamOff;
}
void Segmen::displayMenitOff(){
  Segmen::alarm = Segmen::modeMenitOff;
}
void Segmen::displayTanggalOff(){
  Segmen::alarm = Segmen::modeTanggalOff;
}
void Segmen::displayBualnOff(){
  Segmen::alarm = Segmen::modeBualnOff;
}
void Segmen::displayTahunOff(){
  Segmen::alarm = Segmen::modeTahunOff;
}
void Segmen::displayOff(){
  Segmen::alarm = Segmen::modeOff;
}

void Segmen::loop( ){
    digitalWrite(Segmen::strobe,LOW);
    for (unsigned char i = 35; i < 36; i--) {
        unsigned char j = Segmen::buffer[i];

        if (Segmen::alarm == Segmen::modeImsya){    //imsya
            if(i>15) j=Segmen::dataJadwal[10];
        }
        if (Segmen::alarm == Segmen::modeSubuh){       //subuh
            if( i>11 && i<16 ){
                j=Segmen::dataJadwal[10];
            }
            if( i>19 ){
                j=Segmen::dataJadwal[10];
            }
        }
        if (Segmen::alarm == Segmen::modeDzuhur){       //dzuhur
            if( i>11 && i<20 ){
                j=Segmen::dataJadwal[10];
            }
            if( i>23 ){
                j=Segmen::dataJadwal[10];
            }
        }
        if (Segmen::alarm == Segmen::modeAshar){       //ashar
            if( i>11 && i<24 ){
                j=Segmen::dataJadwal[10];
            }
            if( i>27 ){
                j=Segmen::dataJadwal[10];
            }
        }
        if (Segmen::alarm == Segmen::modeMaghrib){       //maghrib
            if( i>11 && i<28 ){
                j=Segmen::dataJadwal[10];
            }
            if( i>31 ){
                j=Segmen::dataJadwal[10];
            }
        }
        if (Segmen::alarm == Segmen::modeIsya){       //isya
            if( i>11 && i<32 ){
                j=Segmen::dataJadwal[10];
            }
        }
        if (Segmen::alarm == Segmen::modeJamOff){       //jam off
            if( i<2 ){
                j=Segmen::dataJadwal[10];
            }
        }

        if (Segmen::alarm == Segmen::modeMenitOff){       //menit off
            if( i > 1 && i < 4 ){
                j=Segmen::dataJadwal[10];
            }
        }

        if (Segmen::alarm == Segmen::modeJamOff){       //jam off
            if( i>3 ){
                j=Segmen::dataJadwal[10];
            }
        }

        for(unsigned char k = 0;k<8;k++ ){
            if((j&0x80)== 0x80){
              digitalWrite(Segmen::data,HIGH);
            }
            else {
              digitalWrite(Segmen::data,LOW);
            }
            j = (j<<1)|(j>>7);
            digitalWrite(Segmen::sck,HIGH);
            digitalWrite(Segmen::sck,LOW);
        }
    }
    digitalWrite(Segmen::strobe,HIGH);
}
Segmen::~Segmen()
{
}
