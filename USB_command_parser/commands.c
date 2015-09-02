//
//  commands.c
//  USB_command_parser
//
//  Created by Bendegúz Hoffmann on 2015. 08. 30..
//  Copyright (c) 2015. Bendegúz Hoffmann. All rights reserved.
//

#include "commands.h"
#include <inttypes.h>

uint32_t parse(uint8_t *buffer, uint8_t *message_queue_ptr)
{
    uint32_t is_valid_message=0;
    uint32_t message_queue_index=0;
    uint32_t sof_index=0;
    uint32_t eof_index=0;
    
    for(sof_index=0; sof_index<buffer_size;sof_index++ )                                        /* iterating through the buffer                                                         */
    {//
        if (buffer[sof_index]==start_of_frame)                                                  /* looking for start of frame character                                                 */
        {
            for(eof_index=sof_index; eof_index<buffer_size;eof_index++ )                        /* iterating through the buffer                                                         */
            {
                if ((buffer[eof_index]==end_of_frame)&&(eof_index>sof_index))                   /* looking for end of frame character                                                   */
                {
                    is_valid_message=1;                                                         /* means we have a message                                                              */
                    switch(buffer[sof_index+1])                                                 /* sort the different type of messages                                                  */
                    {
                        case acknowledge:
                            message_queue_ptr[message_queue_index]=acknowledge;                 /* update the message queue with the type of the recived message                        */
                            message_queue_index++;                                              /* increment the message queue index variable                                           */
                            message_queue_index&= 127;                                          /* if the message queue index is bigger than 127 after the equation the value will be 0 */
                            printf("ack\n\r");
                            break;
                        
                        case request:
                            message_queue_ptr[message_queue_index]=request;
                            message_queue_index++;
                            message_queue_index&= 127;
                            printf("req\n\r");
                            break;
                        
                        case data:
                           message_queue_ptr[message_queue_index]=data;
                            message_queue_index++;
                            message_queue_index&= 127;
                            printf("data\n\r");
                            break;
                        
                        case handshake:
                            message_queue_ptr[message_queue_index]=handshake;
                            message_queue_index++;
                            message_queue_index&= 127;
                            printf("shake\n\r");
                            break;
                    }
                    break;                                                                          /* find the whole message we can brake from it and iterrating to find the next sof  */
                }
                
            }
            
        }
        
    }
    return is_valid_message;
}

uint32_t send_message(uint32_t fd, uint32_t type, uint8_t *buffer)
{
    
    
    
    
    
    return 0;
}