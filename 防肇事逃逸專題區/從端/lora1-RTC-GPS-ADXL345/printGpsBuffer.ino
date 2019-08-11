//输出解析后的数据
void printGpsBuffer()
{
    if (Save_Data.isParseData)
    {
        Save_Data.isParseData = false;

        Serial.print("Save_Data.UTCTime = ");
        Serial.println(Save_Data.UTCTime);
        
        if(Save_Data.isUsefull)
        {
            Save_Data.isUsefull = false;
            Serial.print("Save_Data.latitude = ");
            Serial.println(Save_Data.latitude);
            Serial.print("Save_Data.N_S = ");
            Serial.println(Save_Data.N_S);
            Serial.print("Save_Data.longitude = ");
            Serial.println(Save_Data.longitude);
            Serial.print("Save_Data.E_W = ");
            Serial.println(Save_Data.E_W);
        }
        else
        {
            Serial.println("GPS DATA is not usefull!");
        }

    }
}
