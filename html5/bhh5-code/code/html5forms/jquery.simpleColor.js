/***
 * Excerpted from "HTML5 and CSS3",
 * published by The Pragmatic Bookshelf.
 * Copyrights apply to this code. It may not be used to create training material, 
 * courses, books, articles, and the like. Contact us if you are in doubt.
 * We make no guarantees that this code is fit for any purpose. 
 * Visit http://www.pragmaticprogrammer.com/titles/bhh5 for more book information.
***/
/*
 * jQuery simpleColor plugin
 * @requires jQuery v1.1 or later
 *
 * Examples at: http://recurser.com/articles/2007/12/18/jquery-simplecolor-color-picker/
 * Dual licensed under the MIT and GPL licenses:
 *   http://www.opensource.org/licenses/mit-license.php
 *   http://www.gnu.org/licenses/gpl.html
 *
 * Revision: $Id$
 * Version: 1.0.0  Aug-03-2007
 */
 (function($) {
/**
 * simpleColor() provides a mechanism for displaying simple color-pickers.
 *
 * If an options Object is provided, the following attributes are supported:
 *
 *  defaultColor: Default (initially selected) color
 *                 default value: '#FFF'
 *
 *  border:       CSS border properties
 *                 default value: '1px solid #000'
 *
 *  cellWidth:    Width of each individual color cell
 *                 default value: 10
 *
 *  cellHeight:   Height of each individual color cell
 *                 default value: 10
 *
 *  cellMargin:   Margin of each individual color cell
 *                 default value: 1
 *
 *  boxWidth:     Width of the color display box
 *                 default value: 115px
 *
 *  boxHeight:    Height of the color display box
 *                 default value: 20px
 *
 *  columns:      Number of columns to display. Color order may look strange if this is altered
 *                 default value: 16
 *
 *  insert:       The position to insert the color picker. 'before' or 'after'
 *                 default value: 'after'
 */
$.fn.simpleColor = function(options) {
	
	var default_colors = 
		['990033','ff3366','cc0033','ff0033','ff9999','cc3366','ffccff','cc6699',
		'993366','660033','cc3399','ff99cc','ff66cc','ff99ff','ff6699','cc0066',
		'ff0066','ff3399','ff0099','ff33cc','ff00cc','ff66ff','ff33ff','ff00ff',
		'cc0099','990066','cc66cc','cc33cc','cc99ff','cc66ff','cc33ff','993399',
		'cc00cc','cc00ff','9900cc','990099','cc99cc','996699','663366','660099',
		'9933cc','660066','9900ff','9933ff','9966cc','330033','663399','6633cc',
		'6600cc','9966ff','330066','6600ff','6633ff','ccccff','9999ff','9999cc',
		'6666cc','6666ff','666699','333366','333399','330099','3300cc','3300ff',
		'3333ff','3333cc','0066ff','0033ff','3366ff','3366cc','000066','000033',
		'0000ff','000099','0033cc','0000cc','336699','0066cc','99ccff','6699ff',
		'003366','6699cc','006699','3399cc','0099cc','66ccff','3399ff','003399',
		'0099ff','33ccff','00ccff','99ffff','66ffff','33ffff','00ffff','00cccc',
		'009999','669999','99cccc','ccffff','33cccc','66cccc','339999','336666',
		'006666','003333','00ffcc','33ffcc','33cc99','00cc99','66ffcc','99ffcc',
		'00ff99','339966','006633','336633','669966','66cc66','99ff99','66ff66',
		'339933','99cc99','66ff99','33ff99','33cc66','00cc66','66cc99','009966',
		'009933','33ff66','00ff66','ccffcc','ccff99','99ff66','99ff33','00ff33',
		'33ff33','00cc33','33cc33','66ff33','00ff00','66cc33','006600','003300',
		'009900','33ff00','66ff00','99ff00','66cc00','00cc00','33cc00','339900',
		'99cc66','669933','99cc33','336600','669900','99cc00','ccff66','ccff33',
		'ccff00','999900','cccc00','cccc33','333300','666600','999933','cccc66',
		'666633','999966','cccc99','ffffcc','ffff99','ffff66','ffff33','ffff00',
		'ffcc00','ffcc66','ffcc33','cc9933','996600','cc9900','ff9900','cc6600',
		'993300','cc6633','663300','ff9966','ff6633','ff9933','ff6600','cc3300',
		'996633','330000','663333','996666','cc9999','993333','cc6666','ffcccc',
		'ff3333','cc3333','ff6666','660000','990000','cc0000','ff0000','ff3300',
		'cc9966','ffcc99','ffffff','cccccc','999999','666666','333333','000000',
		'000000','000000','000000','000000','000000','000000','000000','000000'];
		
	// Option defaults
    options = $.extend({
        defaultColor:  this.attr('defaultColor') || '#FFF',
        border:        this.attr('border') || '1px solid #000',
        cellWidth:     this.attr('cellWidth') || 10,
        cellHeight:    this.attr('cellHeight') || 10,
        cellMargin:    this.attr('cellMargin') || 1,
        boxWidth:      this.attr('boxWidth') || '115px',
        boxHeight:     this.attr('boxHeight') || '20px',
        columns:       this.attr('columns') || 16,
        insert:        this.attr('insert') || 'after',
        buttonClass:   this.attr('buttonClass') || '',
        colors:        this.attr('colors') || default_colors,
        indicator:     this.attr('indicator') || null
    }, options || {});
	
	// Hide the input
	this.hide();
	
	// Figure out the cell dimensions
	options.totalWidth = options.columns * (options.cellWidth + (2 * options.cellMargin));
	if ($.browser.msie) {
		options.totalWidth += 2;
	}
	
	options.totalHeight = Math.ceil(options.colors.length / options.columns) * (options.cellHeight + (2 * options.cellMargin));
	
	// Store these options so they'll be available to the other functions
	// TODO - must be a better way to do this, not sure what the 'official'
	// jQuery method is. Ideally i want to pass these as a parameter to the 
	// each() function but i'm not sure how
	$.simpleColorOptions = options;
	
	this.each(buildSelector);
	
	return this;
	
	
	
	function buildSelector(index) {
		
		var options = $.simpleColorOptions;
		
		// Create a container to hold everything
		var container = $("<div class='simpleColorContainer' />");
		
		// Create the color display box
		var default_color = (this.value && this.value != '') ? this.value : options.defaultColor;
		
		var display_box = $("<div class='simpleColorDisplay' />");
		display_box.css('backgroundColor', default_color);
		display_box.css('border',          options.border);
		display_box.css('width',           options.boxWidth);
		display_box.css('height',          options.boxHeight);
		container.append(display_box);
		
		// Create the select button 
		var select_button = $("<input type='button' value='Select'" + 
							  " class='simpleColorSelectButton "+options.buttonClass+"'>");
		container.append(select_button);
		
		// Create the cancel button
		var cancel_button = $("<input type='button' value='Cancel'" + 
							  " class='simpleColorCancelButton "+options.buttonClass+"'>");
		cancel_button.hide();
		container.append(cancel_button);
		
		// Bind the select button to display the chooser
		select_button.bind('click', {
				container: container, 
				input: this, 
				cancel_button: cancel_button, 
				display_box: display_box}, 
			function (event) {
				$(this).hide();
				event.data.cancel_button.show();
				
				// Use an existing chooser if there is one
				if (event.data.container.chooser) {
					event.data.container.chooser.show();
					
				// Build the chooser
				} else {
		
					// Make a chooser div to hold the cells
					var chooser = $("<div class='simpleColorChooser'/>");
					chooser.css('border',  options.border);
					chooser.css('margin',  '0px');
					chooser.css('margin-top',  '3px');
					chooser.css('width',   options.totalWidth + 'px');
					chooser.css('height',  options.totalHeight + 'px');
					
					event.data.container.chooser = chooser;
					event.data.container.append(chooser);
					
					// Create the cells
					for (var i=0; i<options.colors.length; i++) {
						var cell = $("<div class='simpleColorCell' id='" + options.colors[i] + "'/>");
						cell.css('width',           options.cellWidth + 'px');
						cell.css('height',          options.cellHeight + 'px');
						cell.css('margin',          options.cellMargin + 'px');
						cell.css('cursor',          'pointer');
						cell.css('lineHeight',      options.cellHeight + 'px');
						cell.css('fontSize',        '1px');
						cell.css('float',           'left');
						cell.css('backgroundColor', '#'+options.colors[i]);
						chooser.append(cell);
						
						cell.bind('click', {
								input: event.data.input, 
								chooser: chooser, 
								select_button: select_button, 
								cancel_button: cancel_button, 
								display_box: display_box}, 
							function(event) {
								event.data.input.value = '#' + this.id;
								event.data.display_box.css('backgroundColor', '#' + this.id);
								event.data.chooser.hide();
								event.data.cancel_button.hide();
								event.data.display_box.show();
								event.data.select_button.show();
							}
						);
					}
				}
			}
		);
		
		// Bind the cancel button to hide the chooser
		cancel_button.bind('click', {
				container: container, 
				select_button: select_button, 
				display_box: display_box}, 
			function (event) {
				$(this).hide();
				event.data.container.find('.simpleColorChooser').hide();
				event.data.display_box.show();
				event.data.select_button.show();
			}
		);
		
		$(this).after(container);
		
	};
};
	
/*
 * Close the given color selectors
 */
$.fn.closeSelector = function() {
	this.each( function(index) {
		var container = $(this).parent().find('div.simpleColorContainer');
		container.find('.simpleColorCancelButton').hide();
		container.find('.simpleColorChooser').hide();
		container.find('.simpleColorDisplay').show();
		container.find('.simpleColorSelectButton').show();
	});
	
	return this;
}
	
	
	


})(jQuery);
