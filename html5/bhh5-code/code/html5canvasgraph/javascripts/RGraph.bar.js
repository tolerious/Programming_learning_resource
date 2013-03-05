/***
 * Excerpted from "HTML5 and CSS3",
 * published by The Pragmatic Bookshelf.
 * Copyrights apply to this code. It may not be used to create training material, 
 * courses, books, articles, and the like. Contact us if you are in doubt.
 * We make no guarantees that this code is fit for any purpose. 
 * Visit http://www.pragmaticprogrammer.com/titles/bhh5 for more book information.
***/
// THIS FILE HAS BEEN MINIFIED

if(typeof(RGraph) == 'undefined') RGraph = {};RGraph.Bar = function (id, data)
{
this.id = id;this.canvas = document.getElementById(id);this.context = this.canvas.getContext ? this.canvas.getContext("2d") : null;this.canvas.__object__ = this;this.type = 'bar';this.max = 0;this.stackedOrGrouped = false;this.properties = [];this.properties['chart.background.barcolor1'] = 'rgba(0,0,0,0)';this.properties['chart.background.barcolor2'] = 'rgba(0,0,0,0)';this.properties['chart.background.grid'] = true;this.properties['chart.background.grid.color'] = '#ddd';this.properties['chart.background.grid.width'] = 1;this.properties['chart.background.grid.hsize'] = 20;this.properties['chart.background.grid.vsize'] = 20;this.properties['chart.background.grid.vlines'] = true;this.properties['chart.background.grid.hlines'] = true;this.properties['chart.background.grid.border'] = true;this.properties['chart.ytickgap'] = 20;this.properties['chart.smallyticks'] = 3;this.properties['chart.largeyticks'] = 5;this.properties['chart.hmargin'] = 5;this.properties['chart.strokecolor'] = '#666';this.properties['chart.axis.color'] = 'black';this.properties['chart.gutter'] = 25;this.properties['chart.labels'] = null;this.properties['chart.labels.ingraph'] = null;this.properties['chart.labels.above'] = false;this.properties['chart.xaxispos'] = 'bottom';this.properties['chart.yaxispos'] = 'left';this.properties['chart.text.color'] = 'black';this.properties['chart.text.size'] = 10;this.properties['chart.text.angle'] = 0;this.properties['chart.text.font'] = 'Verdana';this.properties['chart.ymax'] = null;this.properties['chart.title'] = '';this.properties['chart.title.vpos'] = null;this.properties['chart.colors'] = ['rgb(0,0,255)', '#0f0', '#00f', '#ff0', '#0ff', '#0f0'];this.properties['chart.grouping'] = 'grouped';this.properties['chart.variant'] = 'bar';this.properties['chart.shadow'] = false;this.properties['chart.shadow.color'] = '#666';this.properties['chart.shadow.offsetx'] = 3;this.properties['chart.shadow.offsety'] = 3;this.properties['chart.shadow.blur'] = 3;this.properties['chart.tooltips'] = null;this.properties['chart.tooltip.effect'] = 'fade';this.properties['chart.background.hbars'] = null;this.properties['chart.key'] = [];this.properties['chart.key.background'] = '#fff';this.properties['chart.key.position'] = 'graph';this.properties['chart.key.shadow'] = false;this.properties['chart.contextmenu'] = null;this.properties['chart.line'] = null;this.properties['chart.units.pre'] = '';this.properties['chart.units.post'] = '';this.properties['chart.scale.decimals'] = 0;this.properties['chart.crosshairs'] = false;this.properties['chart.crosshairs.color'] = '#333';this.properties['chart.linewidth'] = null;this.properties['chart.annotatable'] = false;this.properties['chart.annotate.color'] = 'black';this.properties['chart.zoom.factor'] = 1.5;this.properties['chart.zoom.fade.in'] = true;this.properties['chart.zoom.fade.out'] = true;this.properties['chart.zoom.hdir'] = 'right';this.properties['chart.zoom.vdir'] = 'down';this.properties['chart.zoom.frames'] = 10;this.properties['chart.zoom.delay'] = 50;this.properties['chart.zoom.shadow'] = true;if(!this.canvas){
alert('[BAR] No canvas support');return;}
if(typeof(RGraph) == 'undefined'){
alert('[BAR] Fatal error: The common library does not appear to have been included');}
for (i=0; i<data.length; ++i){
if(typeof(data[i]) == 'object'){
this.stackedOrGrouped = true;}
}
this.data = data;this.coords = [];}
RGraph.Bar.prototype.Set = function (name, value)
{
if(name == 'chart.labels.abovebar'){
name = 'chart.labels.above';}
this.properties[name.toLowerCase()] = value;}
RGraph.Bar.prototype.Get = function (name)
{
if(name == 'chart.labels.abovebar'){
name = 'chart.labels.above';}
return this.properties[name];}
RGraph.Bar.prototype.Draw = function ()
{
if(   (this.Get('chart.variant') == 'pyramid' || this.Get('chart.variant') == 'dot')
&& typeof(this.Get('chart.tooltips')) == 'object'
&& this.Get('chart.tooltips')
&& this.Get('chart.tooltips').length > 0){
alert('[BAR] (' + this.id + ') Sorry, tooltips are not supported with dot or pyramid charts');}
this.coords = [];this.max = 0;this.grapharea = this.canvas.height - ( (2 * this.Get('chart.gutter')));this.halfgrapharea = this.grapharea / 2;this.halfTextHeight = this.Get('chart.text.size') / 2;RGraph.background.Draw(this);this.Drawbars();this.DrawAxes();this.DrawLabels();if(this.Get('chart.key').length){
RGraph.DrawKey(this, this.Get('chart.key'), this.Get('chart.colors'));}
RGraph.ShowContext(this);var line = this.Get('chart.line');if(line){
if(line.original_data[0].length != this.data.length){
alert("[BAR] You're adding a line with a differing amount of data points to the bar chart - this is not permitted");}
if(this.Get('chart.xaxispos') != line.Get('chart.xaxispos')){
alert("[BAR] Using different X axis positions when combining the Bar and Line is not advised");}
line.Set('chart.gutter', this.Get('chart.gutter'));line.Set('chart.noaxes', true);line.Set('chart.background.barcolor1', 'rgba(0,0,0,0)');line.Set('chart.background.barcolor2', 'rgba(0,0,0,0)');line.Set('chart.background.grid', false);line.Set('chart.ylabels', false);line.Set('chart.hmargin', (this.canvas.width - (2 * this.Get('chart.gutter'))) / (line.original_data[0].length * 2));if(this.Get('chart.ymax')){
line.Set('chart.ymax', this.Get('chart.ymax'));}
line.Draw();}
RGraph.DrawInGraphLabels(this);RGraph.DrawCrosshairs(this);RGraph.Annotate(this);}
RGraph.Bar.prototype.DrawAxes = function ()
{
var gutter = this.Get('chart.gutter');this.context.beginPath();this.context.strokeStyle = this.Get('chart.axis.color');if(this.Get('chart.yaxispos') == 'right'){
this.context.moveTo(this.canvas.width - gutter, gutter);this.context.lineTo(this.canvas.width - gutter, this.canvas.height - gutter);} else {
this.context.moveTo(gutter, gutter);this.context.lineTo(gutter, this.canvas.height - gutter);}
this.context.moveTo(gutter, (this.Get('chart.xaxispos') == 'center' ? this.canvas.height / 2 : this.canvas.height - gutter));this.context.lineTo(this.canvas.width - gutter, this.Get('chart.xaxispos') == 'center' ? this.canvas.height / 2 : this.canvas.height - gutter);var yTickGap = (this.canvas.height - (2 * this.Get('chart.gutter'))) / 10;var xpos = this.Get('chart.yaxispos') == 'left' ? gutter : this.canvas.width - gutter;for (y=gutter;this.Get('chart.xaxispos') == 'center' ? y <= (this.canvas.height - gutter) : y < (this.canvas.height - gutter);y += yTickGap){
if(this.Get('chart.xaxispos') == 'center' && y == (this.canvas.height / 2)) continue;this.context.moveTo(xpos, y);this.context.lineTo(xpos + (this.Get('chart.yaxispos') == 'left' ? -3 : 3), y);}
xTickGap = (this.canvas.width - (2 * gutter) ) / this.data.length;yStart = this.canvas.height - gutter;yEnd = (this.canvas.height - gutter) + 3;if(this.Get('chart.xaxispos') == 'center'){
yStart = (this.canvas.height / 2) + 3;yEnd = (this.canvas.height / 2) - 3;}
for (x=gutter + (this.Get('chart.yaxispos') == 'left' ? xTickGap : 0); x<this.canvas.width - gutter + (this.Get('chart.yaxispos') == 'left' ? 5 : 0); x+=xTickGap){
this.context.moveTo(x, yStart);this.context.lineTo(x, yEnd);}
this.context.stroke();}
RGraph.Bar.prototype.Drawbars = function ()
{
this.context.lineWidth = 1;this.context.strokeStyle = this.Get('chart.strokecolor');this.context.fillStyle = this.Get('chart.colors')[0];var prevX = 0;var prevY = 0;if(this.Get('chart.ymax')){
this.max = this.Get('chart.ymax');this.scale = [
(this.max * (1/5)).toFixed(this.Get('chart.scale.decimals')),
(this.max * (2/5)).toFixed(this.Get('chart.scale.decimals')),
(this.max * (3/5)).toFixed(this.Get('chart.scale.decimals')),
(this.max * (4/5)).toFixed(this.Get('chart.scale.decimals')),
this.max.toFixed(this.Get('chart.scale.decimals'))
];} else {
for (i=0; i<this.data.length; ++i){
if(typeof(this.data[i]) == 'object'){
var value = this.Get('chart.grouping') == 'grouped' ? Number(RGraph.array_max(this.data[i], true)) : Number(RGraph.array_sum(this.data[i])) ;} else {
var value = Number(this.data[i]);}
this.max = Math.max(Math.abs(this.max), Math.abs(value));}
this.scale = RGraph.getScale(this.max);this.max = this.scale[4];if(this.Get('chart.scale.decimals')){
var decimals = this.Get('chart.scale.decimals');this.scale[0] = Number(this.scale[0]).toFixed(decimals);this.scale[1] = Number(this.scale[1]).toFixed(decimals);this.scale[2] = Number(this.scale[2]).toFixed(decimals);this.scale[3] = Number(this.scale[3]).toFixed(decimals);this.scale[4] = Number(this.scale[4]).toFixed(decimals);}
}
if(this.Get('chart.background.hbars') && this.Get('chart.background.hbars').length > 0){
RGraph.DrawBars(this);}
var variant = this.Get('chart.variant');if(variant == '3d'){
RGraph.Draw3DAxes(this);}
for (i=0; i<this.data.length; ++i){
var width = (this.canvas.width - (2 * this.Get('chart.gutter')) ) / this.data.length;;var height = (RGraph.array_sum(this.data[i]) / this.max) * (this.canvas.height - (2 * this.Get('chart.gutter')) );var orig_height = height;if(this.Get('chart.xaxispos') == 'center'){
height /= 2;}
var x = (i * width) + this.Get('chart.gutter');var y = this.Get('chart.xaxispos') == 'center' ? (this.canvas.height / 2) - height : this.canvas.height - height - this.Get('chart.gutter');var hmargin = this.Get('chart.hmargin');var gutter = this.Get('chart.gutter');if(height < 0){
y += height;height = Math.abs(height);}
if(this.Get('chart.shadow')){
this.context.shadowColor = this.Get('chart.shadow.color');this.context.shadowBlur = this.Get('chart.shadow.blur');this.context.shadowOffsetX = this.Get('chart.shadow.offsetx');this.context.shadowOffsetY = this.Get('chart.shadow.offsety');}
this.context.beginPath();if(typeof(this.data[i]) == 'number'){
var barWidth = width - (2 * hmargin);this.context.strokeStyle = this.Get('chart.strokecolor');this.context.fillStyle = this.Get('chart.colors')[0];if(variant == 'bar' || variant == '3d'){
this.context.strokeRect(x + hmargin, y, barWidth, height);this.context.fillRect(x + hmargin, y, width - (2 * hmargin), height);this.coords[i] = [x, y, width, height];if(this.Get('chart.labels.above')){
if(this.Get('chart.shadow')){
RGraph.NoShadow(this);}
var yPos = y - 3;if(this.data[i] < 0){
yPos += height + 6 + (this.Get('chart.text.size') - 4);}
this.context.fillStyle = this.Get('chart.text.color');RGraph.Text(this.context, this.Get('chart.text.font'), this.Get('chart.text.size') - 3, x + hmargin + (barWidth / 2), yPos, RGraph.number_format(this.data[i], this.Get('chart.units.pre'), this.Get('chart.units.post')), null, 'center');}
if(variant == '3d'){
var prevStrokeStyle = this.context.strokeStyle;var prevFillStyle = this.context.fillStyle;this.context.beginPath();this.context.moveTo(x + hmargin, y);this.context.lineTo(x + hmargin + 10, y - 5);this.context.lineTo(x + hmargin + 10 + barWidth, y - 5);this.context.lineTo(x + hmargin + barWidth, y);this.context.closePath();this.context.stroke();                        
this.context.fill();this.context.beginPath();this.context.moveTo(x + hmargin + barWidth, y);this.context.lineTo(x + hmargin + barWidth + 10, y - 5);this.context.lineTo(x + hmargin + barWidth + 10, y + height - 5);this.context.lineTo(x + hmargin + barWidth, y + height);this.context.closePath();this.context.stroke();                        
this.context.fill();this.context.beginPath();this.context.fillStyle = 'rgba(255,255,255,0.3)';this.context.moveTo(x + hmargin, y);this.context.lineTo(x + hmargin + 10, y - 5);this.context.lineTo(x + hmargin + 10 + barWidth, y - 5);this.context.lineTo(x + hmargin + barWidth, y);this.context.lineTo(x + hmargin, y);this.context.closePath();this.context.stroke();this.context.fill();this.context.beginPath();this.context.fillStyle = 'rgba(0,0,0,0.4)';this.context.moveTo(x + hmargin + barWidth, y);this.context.lineTo(x + hmargin + barWidth + 10, y - 5);this.context.lineTo(x + hmargin + barWidth + 10, y - 5 + height);this.context.lineTo(x + hmargin + barWidth, y + height);this.context.lineTo(x + hmargin + barWidth, y);this.context.closePath();this.context.stroke();                        
this.context.fill();this.context.strokeStyle = prevStrokeStyle;this.context.fillStyle = prevFillStyle;}
} else if(variant == 'dot'){
this.context.beginPath();this.context.moveTo(x + (width / 2), y);this.context.lineTo(x + (width / 2), y + height);this.context.stroke();this.context.beginPath();this.context.fillStyle = this.Get('chart.colors')[i];this.context.arc(x + (width / 2), y + (this.data[i] > 0 ? 0 : height), 2, 0, 6.28, 0);this.context.stroke();this.context.fill();} else if(variant == 'pyramid'){
this.context.beginPath();var startY = (this.Get('chart.xaxispos') == 'center' ? (this.canvas.height / 2) : (this.canvas.height - this.Get('chart.gutter')));this.context.moveTo(x + hmargin, startY);this.context.lineTo(
x + hmargin + (barWidth / 2),
y + (this.Get('chart.xaxispos') == 'center' && (this.data[i] < 0) ? height : 0)
);this.context.lineTo(x + hmargin + barWidth, startY);this.context.closePath();this.context.stroke();this.context.fill();} else if(variant == 'arrow'){
var startY = (this.Get('chart.xaxispos') == 'center' ? (this.canvas.height / 2) : (this.canvas.height - this.Get('chart.gutter')));this.context.lineWidth = this.Get('chart.linewidth') ? this.Get('chart.linewidth') : 1;this.context.lineCap = 'round';this.context.beginPath();this.context.moveTo(x + hmargin + (barWidth / 2), startY);this.context.lineTo(x + hmargin + (barWidth / 2), y + (this.Get('chart.xaxispos') == 'center' && (this.data[i] < 0) ? height : 0));this.context.arc(x + hmargin + (barWidth / 2), y + (this.Get('chart.xaxispos') == 'center' && (this.data[i] < 0) ? height : 0), 5, this.data[i] > 0 ? 0.785 : 5.495, this.data[i] > 0 ? 0.785 : 5.495, 0);this.context.moveTo(x + hmargin + (barWidth / 2), y + (this.Get('chart.xaxispos') == 'center' && (this.data[i] < 0) ? height : 0));this.context.arc(x + hmargin + (barWidth / 2), y + (this.Get('chart.xaxispos') == 'center' && (this.data[i] < 0) ? height : 0), 5, this.data[i] > 0 ? 2.355 : 3.925, this.data[i] > 0 ? 2.355 : 3.925, 0);this.context.stroke();this.context.lineWidth = 1;} else {
alert('[BAR] Warning! Unknown chart.variant: ' + variant);}
this.coords.push([x, y, width, height]);} else if(typeof(this.data[i]) == 'object' && this.Get('chart.grouping') == 'stacked'){
var barWidth = width - (2 * hmargin);var redrawCoords = [];var startY = 0;var hmargin = this.Get('chart.hmargin');for (j=0; j<this.data[i].length; ++j){
if(this.Get('chart.xaxispos') == 'center'){
alert("[BAR] It's pointless having the X axis position at the center on a stacked bar chart. Put it at the bottom.");return;}
if(this.data[i][j] < 0){
alert('[BAR] Negative values are not permitted with a stacked bar chart. Try a grouped one instead.');return;}
this.context.strokeStyle = this.Get('chart.strokecolor');this.context.fillStyle = this.Get('chart.colors')[j];var height = (this.data[i][j] / this.max) * (this.canvas.height - (2 * this.Get('chart.gutter')) );if(this.Get('chart.xaxispos') == 'center'){
height /= 2;}
var totalHeight = (RGraph.array_sum(this.data[i]) / this.max) * (this.canvas.height - this.Get('chart.hmargin') - (2 * this.Get('chart.gutter')));this.context.strokeRect(x + hmargin, y, width - (2 * hmargin), height);this.context.fillRect(x + hmargin, y, width - (2 * hmargin), height);this.coords.push([x, y, width, height]);if(j == 0){
var startY = y;var startX = x;}
if(this.Get('chart.shadow')){
redrawCoords.push([x + hmargin, y, width - (2 * hmargin), height, this.Get('chart.colors')[j]]);}
if(this.Get('chart.variant') == '3d'){
var prevFillStyle = this.context.fillStyle;var prevStrokeStyle = this.context.strokeStyle;if(j == 0){
this.context.beginPath();this.context.moveTo(startX + hmargin, y);this.context.lineTo(startX + 10 + hmargin, y - 5);this.context.lineTo(startX + 10 + barWidth + hmargin, y - 5);this.context.lineTo(startX + barWidth + hmargin, y);this.context.closePath();this.context.fill();this.context.stroke();}
this.context.beginPath();this.context.moveTo(startX + barWidth + hmargin, y);this.context.lineTo(startX + barWidth + hmargin + 10, y - 5);this.context.lineTo(startX + barWidth + + hmargin + 10, y - 5 + height);this.context.lineTo(startX + barWidth + hmargin , y + height);this.context.closePath();this.context.fill();this.context.stroke();if(j == 0){
this.context.fillStyle = 'rgba(255,255,255,0.3)';this.context.beginPath();this.context.moveTo(startX + hmargin, y);this.context.lineTo(startX + 10 + hmargin, y - 5);this.context.lineTo(startX + 10 + barWidth + hmargin, y - 5);this.context.lineTo(startX + barWidth + hmargin, y);this.context.closePath();this.context.fill();this.context.stroke();}
this.context.fillStyle = 'rgba(0,0,0,0.4)';this.context.beginPath();this.context.moveTo(startX + barWidth + hmargin, y);this.context.lineTo(startX + barWidth + hmargin + 10, y - 5);this.context.lineTo(startX + barWidth + + hmargin + 10, y - 5 + height);this.context.lineTo(startX + barWidth + hmargin , y + height);this.context.closePath();this.context.fill();this.context.stroke();this.context.strokeStyle = prevStrokeStyle;this.context.fillStyle = prevFillStyle;}
y += height;}
if(this.Get('chart.labels.above')){
RGraph.NoShadow(this);this.context.fillStyle = this.Get('chart.text.color');RGraph.Text(this.context, this.Get('chart.text.font'), this.Get('chart.text.size') - 3, startX + (barWidth / 2) + this.Get('chart.hmargin'), startY - (this.Get('chart.shadow') && this.Get('chart.shadow.offsety') < 0 ? 7 : 4), String(this.Get('chart.units.pre') + RGraph.array_sum(this.data[i]) + this.Get('chart.units.post')), null, 'center');if(this.Get('chart.shadow')){
this.context.shadowColor = this.Get('chart.shadow.color');this.context.shadowBlur = this.Get('chart.shadow.blur');this.context.shadowOffsetX = this.Get('chart.shadow.offsetx');this.context.shadowOffsetY = this.Get('chart.shadow.offsety');}
}
if(this.Get('chart.shadow')){
this.context.shadowColor = 'rgba(0,0,0,0)';for (k=0; k<redrawCoords.length; ++k){
this.context.strokeStyle = this.Get('chart.strokecolor');this.context.fillStyle = redrawCoords[k][4];this.context.strokeRect(redrawCoords[k][0], redrawCoords[k][1], redrawCoords[k][2], redrawCoords[k][3]);this.context.fillRect(redrawCoords[k][0], redrawCoords[k][1], redrawCoords[k][2], redrawCoords[k][3]);this.context.stroke();this.context.fill();}
redrawCoords = [];}
} else if(typeof(this.data[i]) == 'object' && this.Get('chart.grouping') == 'grouped'){
for (j=0; j<this.data[i].length; ++j){
this.context.strokeStyle = this.Get('chart.strokecolor');this.context.fillStyle = this.Get('chart.colors')[j];var individualBarWidth = (width - (2 * hmargin)) / this.data[i].length;var height = (this.data[i][j] / this.max) * (this.canvas.height - (2 * this.Get('chart.gutter')) );if(this.Get('chart.xaxispos') == 'center'){
height /= 2;}
var startX = x + hmargin + (j * individualBarWidth);var startY = (this.Get('chart.xaxispos') == 'bottom' ? this.canvas.height : (this.canvas.height / 2) + this.Get('chart.gutter')) - this.Get('chart.gutter') - height;if(height < 0){
startY += height;height = Math.abs(height);}
this.context.strokeRect(startX, startY, individualBarWidth, height);this.context.fillRect(startX, startY, individualBarWidth, height);y += height;if(this.Get('chart.labels.above')){
this.context.strokeStyle = 'rgba(0,0,0,0)';if(this.Get('chart.shadow')){
RGraph.NoShadow(this);}
var yPos = y - 3;if(this.data[i][j] < 0){
yPos += height + 6 + (this.Get('chart.text.size') - 4);}
this.context.fillStyle = this.Get('chart.text.color');RGraph.Text(this.context, this.Get('chart.text.font'), this.Get('chart.text.size') - 3, startX + (individualBarWidth / 2) , startY - 2, this.data[i][j], null, 'center');if(this.Get('chart.shadow')){
this.context.shadowColor = this.Get('chart.shadow.color');this.context.shadowBlur = this.Get('chart.shadow.blur');this.context.shadowOffsetX = this.Get('chart.shadow.offsetx');this.context.shadowOffsetY = this.Get('chart.shadow.offsety');}
}
if(this.Get('chart.variant') == '3d'){
var prevFillStyle = this.context.fillStyle;var prevStrokeStyle = this.context.strokeStyle;this.context.beginPath();this.context.moveTo(startX, startY);this.context.lineTo(startX + 10, startY - 5);this.context.lineTo(startX + 10 + individualBarWidth, startY - 5);this.context.lineTo(startX + individualBarWidth, startY);this.context.closePath();this.context.fill();this.context.stroke();this.context.beginPath();this.context.moveTo(startX + individualBarWidth, startY);this.context.lineTo(startX + individualBarWidth + 10, startY - 5);this.context.lineTo(startX + individualBarWidth + 10, startY - 5 + height);this.context.lineTo(startX + individualBarWidth , startY + height);this.context.closePath();this.context.fill();this.context.stroke();this.context.fillStyle = 'rgba(255,255,255,0.3)';this.context.beginPath();this.context.moveTo(startX, startY);this.context.lineTo(startX + 10, startY - 5);this.context.lineTo(startX + 10 + individualBarWidth, startY - 5);this.context.lineTo(startX + individualBarWidth, startY);this.context.closePath();this.context.fill();this.context.stroke();this.context.fillStyle = 'rgba(0,0,0,0.4)';this.context.beginPath();this.context.moveTo(startX + individualBarWidth, startY);this.context.lineTo(startX + individualBarWidth + 10, startY - 5);this.context.lineTo(startX + individualBarWidth + 10, startY - 5 + height);this.context.lineTo(startX + individualBarWidth , startY + height);this.context.closePath();this.context.fill();this.context.stroke();this.context.strokeStyle = prevStrokeStyle;this.context.fillStyle = prevFillStyle;}
this.coords.push([startX - this.Get('chart.hmargin'), startY, individualBarWidth + (2 * this.Get('chart.hmargin')), height]);}
}
this.context.closePath();}
RGraph.NoShadow(this);if(this.Get('chart.tooltips')){
RGraph.Register(this);window.onclick = function ()
{
RGraph.Redraw();}
this.canvas.onmousemove = function (e)
{
e = RGraph.FixEventObject(document.all ? event : e);var canvas = document.getElementById(this.id);var obj = canvas.__object__;var mouseCoords = RGraph.getMouseXY(e);for (var i=0; i<obj.coords.length; i++){
var mouseX = mouseCoords[0];var mouseY = mouseCoords[1];var left = obj.coords[i][0];var top = obj.coords[i][1];var width = obj.coords[i][2];var height = obj.coords[i][3];if(mouseX >= (left + 5  ) && mouseX <= (left + width - 5) && mouseY >= top && mouseY <= (top + height) ){
canvas.style.cursor = document.all ? 'hand' : 'pointer';return;}
canvas.style.cursor = null;}
}
this.canvas.onclick = function (e)
{
if(e.button != 0) return;e = RGraph.FixEventObject(document.all ? event : e);var canvas = document.getElementById(this.id);var obj = canvas.__object__;RGraph.Redraw();var mouseCoords = RGraph.getMouseXY(e);for (var i=0; i<obj.coords.length; i++){
var mouseX = mouseCoords[0];var mouseY = mouseCoords[1];var left = obj.coords[i][0];var top = obj.coords[i][1];var width = obj.coords[i][2];var height = obj.coords[i][3];if(mouseX >= (left + 5  ) && mouseX <= (left + width - 5) && mouseY >= top && mouseY <= (top + height) ){
obj.context.beginPath();obj.context.strokeStyle = '#000';obj.context.fillStyle = 'rgba(255,255,255,0.5)';obj.context.strokeRect(left + obj.Get('chart.hmargin'), top, width - (2 * obj.Get('chart.hmargin')), height);obj.context.fillRect(left + obj.Get('chart.hmargin'), top, width - (2 * obj.Get('chart.hmargin')), height);obj.context.stroke();obj.context.fill();if(obj.Get('chart.tooltips')[i]){
RGraph.Tooltip(canvas, obj.Get('chart.tooltips')[i], e.pageX, e.pageY);}
}
}
e.stopPropagation = true;e.cancelBubble = true;}
if(obj = RGraph.Registry.Get('chart.tooltip')){
obj.style.display = 'none';RGraph.Registry.Set('chart.tooltip', null)
}
} else {
this.canvas.onmousemove = null;this.canvas.onclick = null;}
}
RGraph.Bar.prototype.DrawLabels = function ()
{
var context = this.context;var gutter = this.Get('chart.gutter');var text_angle = this.Get('chart.text.angle');var text_size = this.Get('chart.text.size');var labels = this.Get('chart.labels');this.Drawlabels_center();this.Drawlabels_bottom();if(typeof(labels) == 'object' && labels){
var yOffset = 13;var angle = 0;var halign = 'center';if(text_angle == 45 || text_angle == 90){
angle = -1 * text_angle;halign = 'right';yOffset -= 5;}
context.fillStyle = this.Get('chart.text.color');var barWidth = (this.canvas.width - (2 * gutter) ) / labels.length;xTickGap = (this.canvas.width - (2 * gutter)) / labels.length
var i=0;for (x=gutter + (xTickGap / 2); x<=this.canvas.width - gutter; x+=xTickGap){
RGraph.Text(context, this.Get('chart.text.font'),
text_size,
x,
(this.canvas.height - gutter) + yOffset,
String(labels[i++]),
null,
halign,
null,
angle);}
}
}
RGraph.Bar.prototype.Drawlabels_center = function ()
{
var font = this.Get('chart.text.font');this.context.fillStyle = this.Get('chart.text.color');if(this.Get('chart.xaxispos') == 'center'){
var interval = (this.grapharea * (1/10) );var text_size = this.Get('chart.text.size');var gutter = this.Get('chart.gutter');var units_pre = this.Get('chart.units.pre');var units_post = this.Get('chart.units.post');var context = this.context;var align = this.Get('chart.yaxispos') == 'left' ? 'right' : 'left';var xpos = this.Get('chart.yaxispos') == 'left' ? gutter - 5 : this.canvas.width - this.Get('chart.gutter') + 5;this.context.fillStyle = this.Get('chart.text.color');RGraph.Text(context, font, text_size, xpos,                gutter + this.halfTextHeight, RGraph.number_format(this.scale[4], units_pre, units_post), null, align);RGraph.Text(context, font, text_size, xpos, (1*interval) + gutter + this.halfTextHeight, RGraph.number_format(this.scale[3], units_pre, units_post), null, align);RGraph.Text(context, font, text_size, xpos, (2*interval) + gutter + this.halfTextHeight, RGraph.number_format(this.scale[2], units_pre, units_post), null, align);RGraph.Text(context, font, text_size, xpos, (3*interval) + gutter + this.halfTextHeight, RGraph.number_format(this.scale[1], units_pre, units_post), null, align);RGraph.Text(context, font, text_size, xpos, (4*interval) + gutter + this.halfTextHeight, RGraph.number_format(this.scale[0], units_pre, units_post), null, align);var interval = (this.grapharea) / 10;RGraph.Text(context, font, text_size, xpos, (this.grapharea + gutter + this.halfTextHeight) - (4 * interval), '-' + RGraph.number_format(this.scale[0], units_pre, units_post), null, align);RGraph.Text(context, font, text_size, xpos, (this.grapharea + gutter + this.halfTextHeight) - (3 * interval), '-' + RGraph.number_format(this.scale[1], units_pre, units_post), null, align);RGraph.Text(context, font, text_size, xpos, (this.grapharea + gutter + this.halfTextHeight) - (2 * interval), '-' + RGraph.number_format(this.scale[2], units_pre, units_post), null, align);RGraph.Text(context, font, text_size, xpos, (this.grapharea + gutter + this.halfTextHeight) - interval, '-' + RGraph.number_format(this.scale[3], units_pre, units_post), null, align);RGraph.Text(context, font, text_size, xpos,  this.grapharea + gutter + this.halfTextHeight, '-' + RGraph.number_format(this.scale[4], units_pre, units_post), null, align);}
}
RGraph.Bar.prototype.Drawlabels_bottom = function ()
{
this.context.beginPath();this.context.fillStyle = this.Get('chart.text.color');if(this.Get('chart.xaxispos') != 'center'){
var interval = (this.grapharea * (1/5) );var text_size = this.Get('chart.text.size');var units_pre = this.Get('chart.units.pre');var units_post = this.Get('chart.units.post');var gutter = this.Get('chart.gutter');var context = this.context;var align = this.Get('chart.yaxispos') == 'left' ? 'right' : 'left';var xpos = this.Get('chart.yaxispos') == 'left' ? gutter - 5 : this.canvas.width - gutter + 5;var font = this.Get('chart.text.font');RGraph.Text(context, font, text_size, xpos, gutter + this.halfTextHeight, RGraph.number_format(this.scale[4], units_pre, units_post), null, align);RGraph.Text(context, font, text_size, xpos, (1*interval) + gutter + this.halfTextHeight, RGraph.number_format(this.scale[3], units_pre, units_post), null, align);RGraph.Text(context, font, text_size, xpos, (2*interval) + gutter + this.halfTextHeight, RGraph.number_format(this.scale[2], units_pre, units_post), null, align);RGraph.Text(context, font, text_size, xpos, (3*interval) + gutter + this.halfTextHeight, RGraph.number_format(this.scale[1], units_pre, units_post), null, align);RGraph.Text(context, font, text_size, xpos, (4*interval) + gutter + this.halfTextHeight, RGraph.number_format(this.scale[0], units_pre, units_post), null, align);}
this.context.fill();this.context.stroke();}