/**
 * \file
 * 
 * \brief Arduino Uno Bitmap
 * 
 * For use with the Eink Xplained Pro demo. Makes use of the Eink Graphics Service 
 * as part of the Eink Software Library.
 * 
 * \author George Sephton
 * 
 * \copyright Copyright (c) 2019 Ineltek Ltd. All rights reserved.
 * 
 * \page eink_xplained_license License
 * 
 * \brief Software License and Disclaimer
 *
 * \section software_license Software License
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * For a copy of the GNU General Public License, see
 * see <https://www.gnu.org/licenses/>
 *
 * \subsection software_license_logo Logo Use
 *
 * Use of the Ineltek logo, packaged with this software library, is not subject
 * to the above GPL software license and is property of Ineltek GmbH and it subsidiaries.
 * It may not be used for commercial use and may not be used to endorse or promote products
 * without specific prior written permission.
 *
 * \subsection software_license_conditions Conditions
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    software license, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    software license, this list of conditions and the following disclaimer
 *    in the documentation and/or other materials provided with the distribution.
 *
 * 3. The names, trademarks or logos of Eink, Ineltek or Microchip, and any combination
 *    thereof, may not be used to endorse or promote products derived from this
 *    software without specific prior written permission. They are also subject to their
 *    own copyrights and trademarks that may not be expressed here.
 *
 * \section disclaimer Disclaimer
 *
 * THIS SOFTWARE IS PROVIDED BY INELTEK "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * EXPRESSLY AND SPECIFICALLY DISCLAIMED. IN NO EVENT SHALL INELTEK BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 * 
 */  
#ifndef ARDUINO_BARCODE_H_
#define ARDUINO_BARCODE_H_

#define eink_ArduinoBarcode_width_px     95
#define eink_ArduinoBarcode_height_bytes 5

const uint8_t eink_ArduinoBarcode [] = {
    0xF8, 0x00, 0x00, 0x00, 0x3F,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xF8, 0x00, 0x00, 0x00, 0x3F,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xF8, 0x00, 0x00, 0x00, 0x3F,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xF8, 0x00, 0x00, 0x00, 0x3F,
    0xF8, 0x00, 0x00, 0x00, 0x3F,
    0xF8, 0x00, 0x00, 0x00, 0x3F,
    0xF8, 0x00, 0x00, 0x00, 0x3F,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xF8, 0x00, 0x00, 0x00, 0x3F,
    0xF8, 0x00, 0x00, 0x00, 0x3F,
    0xF8, 0x00, 0x00, 0x00, 0x3F,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xF8, 0x00, 0x00, 0x00, 0x3F,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xF8, 0x00, 0x00, 0x00, 0x3F,
    0xF8, 0x00, 0x00, 0x00, 0x3F,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xF8, 0x00, 0x00, 0x00, 0x3F,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xF8, 0x00, 0x00, 0x00, 0x3F,
    0xF8, 0x00, 0x00, 0x00, 0x3F,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xF8, 0x00, 0x00, 0x00, 0x3F,
    0xF8, 0x00, 0x00, 0x00, 0x3F,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xF8, 0x00, 0x00, 0x00, 0x3F,
    0xF8, 0x00, 0x00, 0x00, 0x3F,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xF8, 0x00, 0x00, 0x00, 0x3F,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xF8, 0x00, 0x00, 0x00, 0x3F,
    0xF8, 0x00, 0x00, 0x00, 0x3F,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xF8, 0x00, 0x00, 0x00, 0x3F,
    0xF8, 0x00, 0x00, 0x00, 0x3F,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xF8, 0x00, 0x00, 0x00, 0x3F,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xF8, 0x00, 0x00, 0x00, 0x3F,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xF8, 0x00, 0x00, 0x00, 0x3F,
    0xF8, 0x00, 0x00, 0x00, 0x3F,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xF8, 0x00, 0x00, 0x00, 0x3F,
    0xF8, 0x00, 0x00, 0x00, 0x3F,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xF8, 0x00, 0x00, 0x00, 0x3F,
    0xF8, 0x00, 0x00, 0x00, 0x3F,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xF8, 0x00, 0x00, 0x00, 0x3F,
    0xF8, 0x00, 0x00, 0x00, 0x3F,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xF8, 0x00, 0x00, 0x00, 0x3F,
    0xF8, 0x00, 0x00, 0x00, 0x3F,
    0xF8, 0x00, 0x00, 0x00, 0x3F,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xF8, 0x00, 0x00, 0x00, 0x3F,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xF8, 0x00, 0x00, 0x00, 0x3F,
    0xF8, 0x00, 0x00, 0x00, 0x3F,
    0xF8, 0x00, 0x00, 0x00, 0x3F,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xF8, 0x00, 0x00, 0x00, 0x3F,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xF8, 0x00, 0x00, 0x00, 0x3F,
    0xF8, 0x00, 0x00, 0x00, 0x3F,
    0xF8, 0x00, 0x00, 0x00, 0x3F,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xF8, 0x00, 0x00, 0x00, 0x3F,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xF8, 0x00, 0x00, 0x00, 0x3F,
    0xF8, 0x00, 0x00, 0x00, 0x3F,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xF8, 0x00, 0x00, 0x00, 0x3F,
    0xF8, 0x00, 0x00, 0x00, 0x3F,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xF8, 0x00, 0x00, 0x00, 0x3F,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xF8, 0x00, 0x00, 0x00, 0x3F,
};

#endif /* ARDUINO_BARCODE_H_ */