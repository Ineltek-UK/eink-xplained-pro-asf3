/**
 * \file
 * 
 * \brief Eink XL Xplained Pro Demo - SAMV71 - ED057TC2
 *
 * Microchip ASF3 Variant - release 1.2 - January 2019
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

/** 
 * \mainpage
 * \section intro Introduction
 * This example code demonstrates the use of the Eink XL Xplained Pro (ED057TC2) with the SAMV71 Xplained Pro
 * board, making use of Ineltek's Eink ASF3 Software Library (version 1.2).<br>
 * It uses the following hardware:
 * - the SAMV71 Xplained Pro.
 * - the Eink XL Xplained Extension (ED057TC2) on EXT1 and EXT2.
 *
 * \section setup_steps Setup Steps
 * In order to use the Eink ASF3 Software Library, several ASF services must be added from the ASF
 * wizard. These are:
 * - Delay routines (service)
 * - IOPORT - General purpose I/O service (service)
 *
 * \note Note that this library is not compatible with Atmel START - for this you must use the
 * Eink ASF4 Software Library.
 *
 * Next, the library must be added to the compiler include paths - listed below are the paths used for
 * the example projects:<br>
 * See Project Properties > Toolchain > ARM/GNU C Compiler > Directories:
 * - ../../../../../eink_software_library/ASF3/eink_asf3_1_2
 * - ../../../../../eink_software_library/ASF3/eink_asf3_1_2/fonts
 *
 * Finally the following line must be added directly below the ASF include statement:
 * \code
 * #include <asf.h>
 * #include <eink_asf3_1_2.h>
 * \endcode
 *
 * \subsection setup_initialization Initialization Code
 *
 * We now need to add the initialization code to our main.c file to get the example up and running.
 *
 * First the conf_eink_example.h must be copied from the eink_asf3_1_2 directory
 * into your src/config directory and renamed to conf_eink.h
 *
 * Next, the definition:
 * \code
 * #define eink_project_excluded
 * \endcode
 * must be add above the ASF include if the Eink library is not included in the Solution Explorer:
 * \code
 * #define eink_project_excluded
 * #include <asf.h>
 * #include <eink_asf3_1_2.h>
 * \endcode
 *
 * In this example project, the library is located elsewhere and not in the Solution
 * Explorer, hence why this has been included.
 *
 * To initialize the Eink library for use with the ED057TC2 (UC8159), the eink_ed057tc2_init() function
 * must be called. \ref uc8159_config must be used as the configuration struct. Note that
 * uc8159_get_config_defaults() should be called before making any required changes and passing them to
 * the initialization function:
 *
 * \code
 * struct uc8159_config eink_conf;
 *
 * uc8159_get_config_defaults(&eink_conf);
 * eink_conf.temperature_sensor_settings.sensor_select = EXTERNAL_TEMPERATURE_SENSOR;
 * eink_conf.panel_settings.display_rotation = ROTATE_0;
 * eink_ed057tc2_init(&eink_conf, false);
 * \endcode
 *
 * \section gfx_library GFX Library
 *
 * Once initialized, the library stores a buffer in RAM in order keep track of the canvas - initially
 * it is all white. There are several primitive function that allow for some data to be written to the canvas:
 * - gfx_eink_graphics_fill_screen()
 * - gfx_eink_load_mono_image()
 * - gfx_eink_graphics_draw_line()
 * - gfx_eink_graphics_draw_rect()
 * - gfx_eink_text_write_string()
 * - gfx_eink_set_pixel()
 *
 * The canvas buffer can be uploaded to the display controller with the use of gfx_eink_put_display_buffer()
 *
 * If you decide to load the buffer but refresh the display later on, this can be achieved using the
 * gfx_eink_refresh_display_buffer()
 *
 * \section files Main Files
 * - main.c : Initialize the Eink display and displays some demo screens.
 *
 * \section usage Usage
 * -# Build the program and download it into the board.
 * -# Wait for the RED LED to turn off - indicates initialization is complete.
 * -# Press one of the 3 buttons on the Eink Xplained Extension to change the display.
 *
 * \section compinfo Compilation Information
 * This software was written for the GNU GCC compiler using Atmel Studio 7.0 and requires ASF version
 * 3 (originally compiled using ASF version 3.42.0). Other compilers may or may not work.
 *
 * \section contactinfo Contact Information
 * For further information, visit
 * <A href="http://www.ineltek.com">Ineltek</A>.\n
 */
#define eink_project_excluded

#include <asf.h>

//Add the Eink library
#include <eink_asf3_1_2.h>

//Add any additional fonts needed
#include <Anton/Anton_16pt.h>
#include <Arvo/Arvo_8pt.h>
#include <Arvo/Arvo_10pt.h>
#include <Arvo/Arvo_14pt.h>
#include <Arvo/Arvo_18pt.h>
#include <Arvo/Arvo_22pt.h>
#include <Arvo/Arvo_24pt.h>
#include <Arvo/Arvo_28pt.h>
#include <ArvoBold/ArvoBold_18pt.h>
#include <ArvoBold/ArvoBold_22pt.h>
#include <ArvoBold/ArvoBold_24pt.h>
#include <ArvoBold/ArvoBold_28pt.h>
#include <ArvoBold/ArvoBold_32pt.h>
#include <ArvoBold/ArvoBold_40pt.h>
#include <IBMPlexSans/IBMPlexSans_18pt.h>
#include <Roboto/Roboto_8pt.h>
#include <RobotoBold/RobotoBold_18pt.h>
#include <RobotoLight/RobotoLight_24pt.h>
#include <RobotoMedium/RobotoMedium_14pt.h>
//And any bitmaps
#include <ineltek_logo.h>
#include <kanban_barcode.h>
#include <shipping_barcode.h>

//! \name Eink Xplained LED & Button defines.
//@{
#define EINK_X_LED_0_PIN            EXT1_PIN_8
#define EINK_X_LED_1_PIN            EXT1_PIN_10
#define EINK_X_LED_2_PIN            EXT1_PIN_14

#define EINK_X_BUTTON_0_PIN         EXT1_PIN_7
#define EINK_X_BUTTON_1_PIN         EXT1_PIN_9
#define EINK_X_BUTTON_2_PIN         EXT1_PIN_13
//@}

//Function prototypes
void eink_init_ports(void);
void eink_init_display();

void eink_draw_display(uint8_t display_no);

int main (void)
{
	sysclk_init();
	board_init();

	eink_init_ports();
	eink_init_display();
	
	ioport_set_pin_level(EINK_X_LED_0_PIN, 1);
	while (1)
	{
		if(!ioport_get_pin_level(EINK_X_BUTTON_0_PIN)) {
			while(!ioport_get_pin_level(EINK_X_BUTTON_0_PIN));
			eink_draw_display(0);
		}
		if(!ioport_get_pin_level(EINK_X_BUTTON_1_PIN)) {
			while(!ioport_get_pin_level(EINK_X_BUTTON_1_PIN));
			eink_draw_display(1);
		}
		if(!ioport_get_pin_level(EINK_X_BUTTON_2_PIN)) {
			while(!ioport_get_pin_level(EINK_X_BUTTON_2_PIN));
			eink_draw_display(2);
		}
	}
}

void eink_init_ports(void)
{
	//Setup PORT pins for buttons
	ioport_set_pin_dir(EINK_X_BUTTON_0_PIN, IOPORT_DIR_INPUT);
	ioport_set_pin_dir(EINK_X_BUTTON_1_PIN, IOPORT_DIR_INPUT);
	ioport_set_pin_dir(EINK_X_BUTTON_2_PIN, IOPORT_DIR_INPUT);
	ioport_set_pin_mode(EINK_X_BUTTON_0_PIN, IOPORT_MODE_PULLUP);
	ioport_set_pin_mode(EINK_X_BUTTON_1_PIN, IOPORT_MODE_PULLUP);
	ioport_set_pin_mode(EINK_X_BUTTON_2_PIN, IOPORT_MODE_PULLUP);

	//Setup PORT pins for LEDSs
	ioport_set_pin_dir(EINK_X_LED_0_PIN, IOPORT_DIR_OUTPUT);
	ioport_set_pin_dir(EINK_X_LED_1_PIN, IOPORT_DIR_OUTPUT);
	ioport_set_pin_dir(EINK_X_LED_2_PIN, IOPORT_DIR_OUTPUT);

	//Set initial outputs for LEDs
	ioport_set_pin_level(EINK_X_LED_0_PIN, 0);
	ioport_set_pin_level(EINK_X_LED_1_PIN, 1);
	ioport_set_pin_level(EINK_X_LED_2_PIN, 1);
}

void eink_init_display(void)
{
	struct uc8159_config eink_conf;
	
	uc8159_get_config_defaults(&eink_conf);
	eink_conf.temperature_sensor_settings.sensor_select = EXTERNAL_TEMPERATURE_SENSOR;
	eink_conf.panel_settings.display_rotation = ROTATE_0;
	eink_ed057tc2_init(&eink_conf, false);
}

void eink_draw_display(uint8_t display_no)
{
	uint16_t i;
	char writeText[16];
	
	ioport_set_pin_level(EINK_X_LED_0_PIN, 0);
	
	gfx_eink_graphics_fill_screen(FILL_WHITE);
	
	switch(display_no)
	{
		case 0:
			gfx_eink_load_mono_image(&eink_IneltekLogo, sizeof(eink_IneltekLogo), eink_IneltekLogo_width_px, eink_IneltekLogo_height_bytes, 304, 0, PIXEL_BLACK, PIXEL_WHITE);
			gfx_eink_text_write_string("KANBAN", 9, 5, PIXEL_BLACK, ArvoBold_28pt);
			gfx_eink_graphics_draw_line(0, 58, 600, 58, PIXEL_BLACK);
			
			gfx_eink_text_write_string("Supplier", 9, 63, PIXEL_BLACK, Arvo_10pt);
			gfx_eink_text_write_string("Microchip", 9, 74, PIXEL_BLACK, Arvo_22pt);
			gfx_eink_text_write_string("Storage Area", 275, 63, PIXEL_BLACK, Arvo_10pt);
			gfx_eink_text_write_string("Central 3", 275, 74, PIXEL_BLACK, Arvo_22pt);
			gfx_eink_text_write_string("Location", 450, 63, PIXEL_BLACK, Arvo_10pt);
			gfx_eink_text_write_string("A4-11-GA", 450, 74, PIXEL_BLACK, Arvo_22pt);
			gfx_eink_graphics_draw_line(0, 120, 600, 120, PIXEL_BLACK);
			
			//%C0909CRD%P3500TR800
			gfx_eink_load_mono_image(&eink_Kanban1, sizeof(eink_Kanban1), eink_Kanban1_width_px, eink_Kanban1_height_bytes, 10, 125, PIXEL_BLACK, PIXEL_WHITE);
			gfx_eink_text_write_string("Container", 130, 125, PIXEL_BLACK, Arvo_10pt);
			gfx_eink_text_write_string("0909CRD", 130, 136, PIXEL_BLACK, Arvo_22pt);
			gfx_eink_text_write_string("Package", 290, 125, PIXEL_BLACK, Arvo_10pt);
			gfx_eink_text_write_string("3500TR800", 290, 136, PIXEL_BLACK, Arvo_22pt);
			gfx_eink_text_write_string("Packages/Container", 130, 180, PIXEL_BLACK, Arvo_10pt);
			gfx_eink_text_write_string("50", 130, 191, PIXEL_BLACK, Arvo_22pt);
			gfx_eink_text_write_string("Items/Package", 290, 180, PIXEL_BLACK, Arvo_10pt);
			gfx_eink_text_write_string("3500", 290, 191, PIXEL_BLACK, Arvo_22pt);
			gfx_eink_text_write_string("Handling Code", 480, 125, PIXEL_BLACK, Arvo_10pt);
			gfx_eink_text_write_string("AS", 492, 136, PIXEL_BLACK, ArvoBold_40pt);
			gfx_eink_graphics_draw_line(0, 238, 600, 238, PIXEL_BLACK);
			
			gfx_eink_text_write_string("MPN", 9, 243, PIXEL_BLACK, Arvo_10pt);
			gfx_eink_text_write_string("ATSAMG55J19B-MUT", 9, 256, PIXEL_BLACK, Arvo_18pt);
			//ATSAMG55J19B-MUT
			gfx_eink_load_mono_image(&eink_Kanban2, sizeof(eink_Kanban2), eink_Kanban2_width_px, eink_Kanban2_height_bytes, 380, 253, PIXEL_BLACK, PIXEL_WHITE);
			//*MPN*ATSAMG55J19B-MUT*LA411GA*SC3*SMICROCHIP*ID*9004127AA
			gfx_eink_load_mono_image(&eink_Kanban3, sizeof(eink_Kanban3), eink_Kanban3_width_px, eink_Kanban3_height_bytes, 9, 295, PIXEL_BLACK, PIXEL_WHITE);
			
			gfx_eink_graphics_draw_rect(172, 295, 420, 153, PIXEL_BLACK, FILL_WHITE);
			gfx_eink_text_write_string("Stock Levels", 177, 298, PIXEL_BLACK, Arvo_18pt);
			gfx_eink_text_write_string("Last updated: 08:45 17/10/2018", 400, 299, PIXEL_BLACK, Arvo_10pt);
			
			gfx_eink_text_write_string("Containers  Packages  Items", 185, 335, PIXEL_BLACK, Arvo_10pt);
			gfx_eink_text_write_string("      7           2       42", 185, 352, PIXEL_BLACK, Arvo_18pt);
			gfx_eink_text_write_string("Total Pieces", 185, 390, PIXEL_BLACK, Arvo_10pt);
			gfx_eink_text_write_string("1,232,042", 185, 407, PIXEL_BLACK, Arvo_18pt);
			
			gfx_eink_text_write_string("Re-order at (items):", 430, 335, PIXEL_BLACK, Arvo_10pt);
			gfx_eink_text_write_string("35,000", 430, 352, PIXEL_BLACK, Arvo_18pt);
			gfx_eink_text_write_string("Current Lead Time:", 430, 390, PIXEL_BLACK, Arvo_10pt);
			gfx_eink_text_write_string("8 weeks", 430, 407, PIXEL_BLACK, Arvo_18pt);
			break;
		case 1:
			gfx_eink_graphics_draw_rect(10, 80, 580, 362, PIXEL_BLACK, FILL_BLACK);
			gfx_eink_load_mono_image(&eink_IneltekLogo, sizeof(eink_IneltekLogo), eink_IneltekLogo_width_px, eink_IneltekLogo_height_bytes, 290, 378, PIXEL_WHITE, PIXEL_BLACK);
			
			gfx_eink_text_write_string("Lecture Hall 1", 10, 10, PIXEL_BLACK, ArvoBold_40pt);
			gfx_eink_text_write_string("Tue 8th May 2018 ", 20, 400, PIXEL_WHITE, Arvo_18pt);
			
			gfx_eink_text_write_string("9:57 am ", 20, 85, PIXEL_WHITE, ArvoBold_32pt);
			gfx_eink_text_write_string("Currently Available", 240, 100, PIXEL_WHITE, ArvoBold_18pt);
			gfx_eink_text_write_string("Next session - Starting in 3 mins", 250, 135, PIXEL_WHITE, Arvo_14pt);
			
			gfx_eink_text_write_string("10:00 am", 45, 180, PIXEL_WHITE, Arvo_24pt);
			gfx_eink_text_write_string("- 10:55 am", 70, 210, PIXEL_WHITE, Arvo_18pt);
			gfx_eink_text_write_string("Introduction to MPUs", 240, 186, PIXEL_WHITE, Arvo_18pt);
			gfx_eink_text_write_string("John Taylor", 250, 221, PIXEL_WHITE, Arvo_14pt);
			
			gfx_eink_graphics_draw_rect(10, 320, 580, 50, PIXEL_WHITE, FILL_WHITE);
			gfx_eink_text_write_string("Please note: Fire Alarms will be tested today at 2pm", 65, 335, PIXEL_BLACK, Arvo_14pt);
			break;
		case 2:
			gfx_eink_load_mono_image(&eink_IneltekLogo, sizeof(eink_IneltekLogo), eink_IneltekLogo_width_px, eink_IneltekLogo_height_bytes, 0, 0, PIXEL_BLACK, PIXEL_WHITE);
			gfx_eink_graphics_draw_rect(317, 18, 65, 40, PIXEL_BLACK, FILL_BLACK);
			gfx_eink_text_write_string("EXP", 325, 22, PIXEL_WHITE, ArvoBold_18pt);
			gfx_eink_graphics_draw_line(0, 58, 600, 58, PIXEL_BLACK);
			
			gfx_eink_text_write_string("From:", 9, 63, PIXEL_BLACK, Arvo_10pt);
			gfx_eink_text_write_string("E Ink Holdings Inc.", 54, 60, PIXEL_BLACK, Arvo_14pt);
			gfx_eink_text_write_string("No. 199, Hwaya Road 2", 54, 82, PIXEL_BLACK, Arvo_14pt);
			gfx_eink_text_write_string("Kueishan", 54, 104, PIXEL_BLACK, Arvo_14pt);
			gfx_eink_text_write_string("Taoyuan 33383", 54, 126, PIXEL_BLACK, Arvo_14pt);
			gfx_eink_text_write_string("Taiwan", 54, 148, PIXEL_BLACK, Arvo_14pt);
			
			gfx_eink_text_write_string("Origin:", 546, 60, PIXEL_BLACK, Arvo_10pt);
			gfx_eink_text_write_string("TAI", 543, 74, PIXEL_BLACK, ArvoBold_18pt);
			gfx_eink_text_write_string("Contact: 2005200163", 460, 104, PIXEL_BLACK, Arvo_10pt);
			gfx_eink_text_write_string("EXPRESS", 433, 128, PIXEL_BLACK, ArvoBold_24pt);
			gfx_eink_graphics_draw_line(0, 176, 600, 176, PIXEL_BLACK);
			
			gfx_eink_text_write_string("To:", 9, 183, PIXEL_BLACK, Arvo_10pt);
			gfx_eink_text_write_string("INELTEK LTD.", 54, 180, PIXEL_BLACK, Arvo_18pt);
			gfx_eink_text_write_string("2B Saturn House, Calleva Park", 54, 210, PIXEL_BLACK, Arvo_18pt);
			gfx_eink_text_write_string("Aldermaston RG7 8HA", 54, 236, PIXEL_BLACK, Arvo_22pt);
			gfx_eink_text_write_string("UNITED KINGDOM (UK)", 54, 272, PIXEL_BLACK, Arvo_22pt);
			
			gfx_eink_text_write_string("Piece:", 546, 183, PIXEL_BLACK, Arvo_10pt);
			gfx_eink_text_write_string("1/1", 550, 195, PIXEL_BLACK, ArvoBold_18pt);
			gfx_eink_text_write_string("Pce/Shpt Weight:", 475, 226, PIXEL_BLACK, Arvo_10pt);
			gfx_eink_text_write_string("1.2 kg", 514, 238, PIXEL_BLACK, ArvoBold_18pt);
			gfx_eink_text_write_string("Ref: 484", 540, 295, PIXEL_BLACK, Arvo_10pt);
			//gfx_eink_graphics_draw_line(0, 316, 600, 316, PIXEL_BLACK);

			gfx_eink_load_mono_image(&eink_ShippingBarcode, sizeof(eink_ShippingBarcode), eink_ShippingBarcode_width_px, eink_ShippingBarcode_height_bytes, 167, 330, PIXEL_BLACK, PIXEL_WHITE);
			gfx_eink_text_write_string("(J) JD01 4600 0024 3373 5713", 174, 405, PIXEL_BLACK, Arvo_14pt);
			break;
	}
	
	/* Send both display buffers to the display. */
	gfx_eink_put_display_buffer(true);
	
	ioport_set_pin_level(EINK_X_LED_0_PIN, 1);
}