//
//  commands.h
//  USB_command_parser
//
//  Created by Bendegúz Hoffmann on 2015. 08. 30..
//  Copyright (c) 2015. Bendegúz Hoffmann. All rights reserved.
//

#ifndef __USB_command_parser__commands__
#define __USB_command_parser__commands__

#include <stdio.h>
#include <inttypes.h>

#define buffer_size     128
#define message_size    128


#define   start_of_frame    0x55
#define   handshake         0x01
#define   request           0x02
#define   data              0x03
#define   acknowledge       0x04
#define   end_of_frame      '\n'


/*!
 @struct message
 @abstract holds one recived frames
 @field message_identifier id of the frame
 @field message_data holds the recived data or commands
 */
struct command_message{
    uint32_t message_type;
    uint8_t message_data[128];
};



/*!
 @struct can_message
 @abstract holds one recived can frame
 @field message_identifier id of the frame
 @field message the message
 */
struct can_message{
    uint64_t message_identifier;
    uint64_t message;
};




/*!
 *
 *  @function parse
 *  @abstract This function is to parse the recived bytes.
 *  @param buffer holds the recived bytes. It is an unsigned char array.
 *  @discussion Every message start with star of frame character. Then a message_type character. This tells the recievert which kind of message have to parse. After that type character there is a data field and then end of frame character. Function will
 *  search for it and if it finds the function will parse it will parse the frame in to the message structure
 *
 *  @var is_valid_message set 1 if there was a message 0 if not. This is also the return value
 *  @var message_queue_index index variable for the message queue
 *  @var sof_index holds the value where was the last start of frame character
 *  @var eof_index holds the value where was the last end of frame character
 *
 * @return 1 if it find a valid frame and 0 if not
 */
uint32_t parse(uint8_t *buffer, uint8_t *message_queue_ptr);

/*!
 *  @brief  This functiion send messages on the desired communication protocol
 *
 *  @param buffer points to the sendable structure
 *  @param fd file descriptor.
 *  @param type which type of message will be send
 *
 *  @return the type of the message
 */
uint32_t send_message(uint32_t fd, uint32_t type, uint8_t *buffer);

#endif /* defined(__USB_command_parser__commands__) */












