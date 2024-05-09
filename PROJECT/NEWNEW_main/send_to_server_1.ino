void send_to_server_1(){

 counter=0;//keeps track of the payload size
  payload_size=0;
  for(int i=0; i<(sizeof(fetch)-1); i++){//run through the URL we're going to use - sizeof() returns +1 extra, so subtract it out
    payload[payload_size+i] = fetch[i];//build up the payload
    counter++;//increment the counter
  }//for int
  payload_size = counter+payload_size;//payload size is just the counter value - more on this when we need to build out the payload with more data
  Serial.println(payload);
 
  if(connect_ESP()){

//Serial.println("connected ESP"); 


   if(read_until_ESP(keyword_b1,sizeof(keyword_b1),5000,0)){//same as before - first d1
   if(read_until_ESP(keyword_doublehash,sizeof(keyword_doublehash),5000,1)){//now ## and mode=1
   for(int i=1; i<=(scratch_data_from_ESP[0]-sizeof(keyword_doublehash)+1); i++)
   d1_from_ESP[i] = scratch_data_from_ESP[i];
   d1_from_ESP[0] = (scratch_data_from_ESP[0]-sizeof(keyword_doublehash)+1);

   Serial.println("D1 recived"); 

   if(read_until_ESP(keyword_b2,sizeof(keyword_b2),5000,0)){//same as before - first d1
   if(read_until_ESP(keyword_doublehash,sizeof(keyword_doublehash),5000,1)){//now ## and mode=1
   for(int i=1; i<=(scratch_data_from_ESP[0]-sizeof(keyword_doublehash)+1); i++)
   d2_from_ESP[i] = scratch_data_from_ESP[i];
   d2_from_ESP[0] = (scratch_data_from_ESP[0]-sizeof(keyword_doublehash)+1);

   if(read_until_ESP(keyword_b3,sizeof(keyword_b3),5000,0)){//same as before - first d1
   if(read_until_ESP(keyword_doublehash,sizeof(keyword_doublehash),5000,1)){//now ## and mode=1
   for(int i=1; i<=(scratch_data_from_ESP[0]-sizeof(keyword_doublehash)+1); i++)
   d3_from_ESP[i] = scratch_data_from_ESP[i];
   d3_from_ESP[0] = (scratch_data_from_ESP[0]-sizeof(keyword_doublehash)+1);

   if(read_until_ESP(keyword_b4,sizeof(keyword_b4),5000,0)){//same as before - first d1
   if(read_until_ESP(keyword_doublehash,sizeof(keyword_doublehash),5000,1)){//now ## and mode=1
   for(int i=1; i<=(scratch_data_from_ESP[0]-sizeof(keyword_doublehash)+1); i++)
   d4_from_ESP[i] = scratch_data_from_ESP[i];
   d4_from_ESP[0] = (scratch_data_from_ESP[0]-sizeof(keyword_doublehash)+1);

   if(read_until_ESP(keyword_b5,sizeof(keyword_b5),5000,0)){//same as before - first d1
   if(read_until_ESP(keyword_doublehash,sizeof(keyword_doublehash),5000,1)){//now ## and mode=1
   for(int i=1; i<=(scratch_data_from_ESP[0]-sizeof(keyword_doublehash)+1); i++)
   d5_from_ESP[i] = scratch_data_from_ESP[i];
   d5_from_ESP[0] = (scratch_data_from_ESP[0]-sizeof(keyword_doublehash)+1);

   
   
   //now that we have our data, go wait for the connection to disconnect 
   //- the ESP will eventually return 'Unlink'
   //delay(10);
   Serial.println("FOUND DATA & DISCONNECTED");
   serial_dump_ESP();//now we can clear out the buffer and read whatever is still there
   //let's see how the data looks

   }

                          
   Serial.print("RECEIVED_BOOL_1 = ");//print out LED data and convert to integer
   received_bool_1 = 0;
   for(int i=1; i<=d1_from_ESP[0]; i++){
   //Serial.print(d12_from_ESP[i]);
   received_bool_1 = received_bool_1 + ((d1_from_ESP[i] - 48) * multiplier[d1_from_ESP[0] - i]);
   }
   Serial.println(received_bool_1);  
                          
   Serial.print("RECEIVED_BOOL_2 = ");//print out LED data and convert to integer
   received_bool_2 = 0;
   for(int i=1; i<=d2_from_ESP[0]; i++){
   //Serial.print(d12_from_ESP[i]);
   received_bool_2 = received_bool_2 + ((d2_from_ESP[i] - 48) * multiplier[d2_from_ESP[0] - i]);
   }
   Serial.println(received_bool_2);    
   
   Serial.print("RECEIVED_BOOL_3 = ");//print out LED data and convert to integer
   received_bool_3 = 0;
   for(int i=1; i<=d3_from_ESP[0]; i++){
   //Serial.print(d12_from_ESP[i]);
   received_bool_3 = received_bool_3 + ((d3_from_ESP[i] - 48) * multiplier[d3_from_ESP[0] - i]);
   }
   Serial.println(received_bool_3);     

   Serial.print("RECEIVED_BOOL_4 = ");//print out LED data and convert to integer
   received_bool_4 = 0;
   for(int i=1; i<=d4_from_ESP[0]; i++){
   //Serial.print(d12_from_ESP[i]);
   received_bool_4 = received_bool_4 + ((d4_from_ESP[i] - 48) * multiplier[d4_from_ESP[0] - i]);
   }
   Serial.println(received_bool_4); 

   Serial.print("RECEIVED_BOOL_5 = ");//print out LED data and convert to integer
   received_bool_5 = 0;
   for(int i=1; i<=d5_from_ESP[0]; i++){
   //Serial.print(d12_from_ESP[i]);
   received_bool_5 = received_bool_5 + ((d5_from_ESP[i] - 48) * multiplier[d5_from_ESP[0] - i]);
   }
   Serial.println(received_bool_5); 

   
   
   Serial.println("");
   //that's it!!  
   }//##
   }//B1 
   }//##
   }//B2
   }//##
   }//B3
   }//##
   }//B4
   }//##
   //B5
   
 

   
  }//connect ESP


}//connect web host
