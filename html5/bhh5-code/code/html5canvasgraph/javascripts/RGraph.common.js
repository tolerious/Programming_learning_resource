/***
 * Excerpted from "HTML5 and CSS3",
 * published by The Pragmatic Bookshelf.
 * Copyrights apply to this code. It may not be used to create training material, 
 * courses, books, articles, and the like. Contact us if you are in doubt.
 * We make no guarantees that this code is fit for any purpose. 
 * Visit http://www.pragmaticprogrammer.com/titles/bhh5 for more book information.
***/
// THIS FILE HAS BEEN MINIFIED

if(typeof(RGraph) == 'undefined') RGraph = {};RGraph.Registry = {};RGraph.Registry.store = []
RGraph.background = {};RGraph.objects = [];RGraph.getScale = function (max)
{
if(max == 0){
return ['0.2', '0.4', '0.6', '0.8', '1.0'];}
var original_max = max;if(max <= 1){
if(max > 0.5){
return [0.2,0.4,0.6,0.8, Number(1).toFixed(1)];} else if(max >= 0.1){
return [0.1,0.2,0.3,0.4,0.5];} else {
var tmp = max;var exp = 0;while (tmp < 1.01){
exp += 1;tmp *= 10;}
var ret = ['2e-' + exp, '4e-' + exp, '6e-' + exp, '8e-' + exp, '10e-' + exp];if(max <= ('5e-' + exp)){
ret = ['1e-' + exp, '2e-' + exp, '3e-' + exp, '4e-' + exp, '5e-' + exp];}
return ret;}
}
if(String(max).indexOf('.') > 0){
max = String(max).replace(/\.\d+$/, '');}
var interval = Math.pow(10, Number(String(Number(max)).length - 1));var topValue = interval;while (topValue < max){
topValue += (interval / 2);}
if(Number(original_max) > Number(topValue)){
topValue += (interval / 2);}
if(max < 10){
topValue = (Number(original_max) <= 5 ? 5 : 10);}
return [topValue * (1/5), topValue * (2/5), topValue * (3/5), topValue * (4/5), topValue];}
RGraph.array_max = function (arr)
{
var max = null;for (var i=0; i<arr.length; ++i){
max = (max ? Math.max(max, arguments[1] ? Math.abs(arr[i]) : arr[i]) : arr[i]);}
return max;}
RGraph.array_sum = function (arr)
{
if(typeof(arr) == 'number'){
return arr;}
var i, sum;var len = arr.length;for(i=0,sum=0;i<len;sum+=arr[i++]);return sum;}
RGraph.degrees2Radians = function (degrees)
{
return degrees * (Math.PI / 180);}
RGraph.lineByAngle = function (context, x, y, angle, length)
{
context.arc(x, y, length, angle, angle, false);context.lineTo(x, y);context.arc(x, y, length, angle, angle, false);}
RGraph.Text = function (context, font, size, x, y, text)
{
context.font = (arguments[11] ? 'Bold ': '') + size + 'pt ' + font;var i;var origX = x;var origY = y;var originalFillStyle = context.fillStyle;if(typeof(arguments[6]) == null) arguments[6] = 'bottom';if(typeof(arguments[7]) == null) arguments[7] = 'left';if(typeof(arguments[8]) == null) arguments[8] = null;if(typeof(arguments[9]) == null) arguments[9] = 0;context.save();context.translate(x, y)
x = 0;y = 0;if(arguments[9]){
context.rotate(arguments[9] / 57.3);}
if(arguments[6]){
var vAlign = arguments[6];if(vAlign == 'center'){
context.translate(0, size / 2);} else if(vAlign == 'top'){
context.translate(0, size);}
}
if(arguments[7]){
var hAlign = arguments[7];var width = context.measureText(text).width;if(hAlign){
if(hAlign == 'center'){
context.translate(-1 * (width / 2), 0)
} else if(hAlign == 'right'){
context.translate(-1 * width, 0)
}
}
}
if(arguments[10]){
var offset = 3;var width = context.measureText(text).width
context.strokeStyle = 'gray';context.fillStyle = arguments[10];context.fillRect(x - offset, y - size - offset, width + (2 * offset), size + (2 * offset));context.strokeRect(x - offset, y - size - offset, width + (2 * offset), size + (2 * offset));}
context.fillStyle = originalFillStyle;context.save();context.fillText(text,0,0);if(arguments[8]){
var width = context.measureText(text).width;context.translate(x, y);context.strokeRect(0, 0, width, 0 - size);context.fillRect(
arguments[7] == 'left' ? 0 : (arguments[7] == 'center' ? width / 2 : width ) - 2,
arguments[6] == 'bottom' ? 0 : (arguments[6] == 'center' ? (0 - size) / 2 : 0 - size) - 2,
4,
4
);}
context.restore();context.restore();}
RGraph.Clear = function (canvas)
{
var width = canvas.width;canvas.width = width;if(arguments[1]){
context = canvas.getContext('2d');context.beginPath();context.fillStyle = arguments[1];context.fillRect(0,0,width,canvas.height);context.fill();}
RGraph.ClearAnnotations(canvas.id);}
RGraph.DrawTitle = function (canvas, text, gutter)
{
var obj = canvas.__object__;var context = canvas.getContext('2d');var size = arguments[4] ? arguments[4] : 12;var centerx = (arguments[3] ? arguments[3] : canvas.width / 2);var keypos = obj.Get('chart.key.position');var vpos = gutter / 2;if(obj.type == 'bar' && obj.Get('chart.variant') == '3d'){
keypos = 'gutter';}
context.beginPath();context.fillStyle = obj.Get('chart.text.color') ? obj.Get('chart.text.color') : 'black';if(keypos && keypos != 'gutter'){
var vCenter = 'center';} else if(!keypos){
var vCenter = 'center';} else {
var vCenter = 'bottom';}
if(typeof(obj.Get('chart.title.vpos')) == 'number'){
vpos = obj.Get('chart.title.vpos') * gutter;}
if(typeof(obj.Get('chart.title.color') != null)){
var oldColor = context.fillStyle
context.fillStyle = obj.Get('chart.title.color');}
var font = obj.Get('chart.text.font');RGraph.Text(context, font, size, centerx, vpos, text, vCenter, 'center', null, null, null, true);context.fillStyle = oldColor;}
RGraph.getMouseXY = function (event)
{
var obj = (document.all ? event.srcElement : event.target);var e = event;var x;var y;if(typeof(e.offsetX) == 'number' && typeof(e.offsetY) == 'number'){
x = e.offsetX;y = e.offsetY;} else {
x = 0;y = 0;while (obj != document.body){
x += obj.offsetLeft;y += obj.offsetTop;obj = obj.offsetParent;}
x = e.pageX - x;y = e.pageY - y;}
return [x, y];}
RGraph.Tooltip = function (canvas, text, x, y)
{
var timers = RGraph.Registry.Get('chart.tooltip.timers');if(timers && timers.length){
for (i=0; i<timers.length; ++i){
clearTimeout(timers[i]);}
}
RGraph.Registry.Set('chart.tooltip.timers', []);RGraph.HideContext();RGraph.Redraw(canvas.id);if(RGraph.Registry.Get('chart.tooltip')){
RGraph.Registry.Get('chart.tooltip').style.display = 'none';RGraph.Registry.Set('chart.tooltip', null);}
RGraph.HideContext();var result = /^id:(.*)/.exec(text);if(result){
text = document.getElementById(result[1]).innerHTML;}
var obj = document.createElement('DIV');obj.className = 'RGraph_tooltip';obj.style.display = 'none';obj.style.position = 'absolute';obj.style.left = 0;obj.style.top = 0;obj.style.backgroundColor = '#ffe';obj.style.color = 'black';obj.style.border = '1px solid rgba(96,96,96,0)';obj.style.visibility = 'visible';obj.style.paddingLeft = '3px';obj.style.paddingRight = '3px';obj.style.fontFamily = 'Tahoma';obj.style.fontSize = '10pt';obj.style.zIndex = 3;obj.style.borderRadius = '5px';obj.style.MozBorderRadius = '5px';obj.style.WebkitBorderRadius = '5px';obj.style.WebkitBoxShadow = 'rgba(96,96,96,0.5) 3px 3px 3px';obj.style.MozBoxShadow = 'rgba(96,96,96,0.5) 3px 3px 3px';obj.style.filter = 'progid:DXImageTransform.Microsoft.Shadow(color=#666666,direction=135)';obj.style.opacity = 0;obj.style.overflow = 'hidden';obj.innerHTML = text;obj.__text__ = text;obj.style.display = 'inline';document.body.appendChild(obj);var width = obj.offsetWidth;var height = obj.offsetHeight;obj.style.width = width + 'px';if( (x + width) > document.body.offsetWidth ){
x = x - width - 7;y = y;var placementLeft = true;obj.style.left = x + 'px';obj.style.top = y + 'px';} else {
x += 5;obj.style.left = x + 'px';obj.style.top = (y - height) + 'px';}
var effect = canvas.__object__.Get('chart.tooltip.effect');if(effect == 'expand'){
obj.style.left = (x + (width / 2)) + 'px';obj.style.top = (y - (height / 2)) + 'px';leftDelta = (width / 2) / 10;topDelta = (height / 2) / 10;obj.style.width = 0;obj.style.height = 0;obj.style.MozBoxShadow = '';obj.style.WebkitBoxShadow = '';obj.style.borderRadius = 0;obj.style.MozBorderRadius = 0;obj.style.WebkitBorderRadius = 0;obj.style.opacity = 1;RGraph.Registry.Get('chart.tooltip.timers').push(setTimeout("if(RGraph.Registry.Get('chart.tooltip')){ RGraph.Registry.Get('chart.tooltip').style.left = (parseInt(RGraph.Registry.Get('chart.tooltip').style.left) - leftDelta) + 'px' }", 25));RGraph.Registry.Get('chart.tooltip.timers').push(setTimeout("if(RGraph.Registry.Get('chart.tooltip')){ RGraph.Registry.Get('chart.tooltip').style.left = (parseInt(RGraph.Registry.Get('chart.tooltip').style.left) - leftDelta) + 'px' }", 50));RGraph.Registry.Get('chart.tooltip.timers').push(setTimeout("if(RGraph.Registry.Get('chart.tooltip')){ RGraph.Registry.Get('chart.tooltip').style.left = (parseInt(RGraph.Registry.Get('chart.tooltip').style.left) - leftDelta) + 'px' }", 75));RGraph.Registry.Get('chart.tooltip.timers').push(setTimeout("if(RGraph.Registry.Get('chart.tooltip')){ RGraph.Registry.Get('chart.tooltip').style.left = (parseInt(RGraph.Registry.Get('chart.tooltip').style.left) - leftDelta) + 'px' }", 100));RGraph.Registry.Get('chart.tooltip.timers').push(setTimeout("if(RGraph.Registry.Get('chart.tooltip')){ RGraph.Registry.Get('chart.tooltip').style.left = (parseInt(RGraph.Registry.Get('chart.tooltip').style.left) - leftDelta) + 'px' }", 125));RGraph.Registry.Get('chart.tooltip.timers').push(setTimeout("if(RGraph.Registry.Get('chart.tooltip')){ RGraph.Registry.Get('chart.tooltip').style.left = (parseInt(RGraph.Registry.Get('chart.tooltip').style.left) - leftDelta) + 'px' }", 150));RGraph.Registry.Get('chart.tooltip.timers').push(setTimeout("if(RGraph.Registry.Get('chart.tooltip')){ RGraph.Registry.Get('chart.tooltip').style.left = (parseInt(RGraph.Registry.Get('chart.tooltip').style.left) - leftDelta) + 'px' }", 175));RGraph.Registry.Get('chart.tooltip.timers').push(setTimeout("if(RGraph.Registry.Get('chart.tooltip')){ RGraph.Registry.Get('chart.tooltip').style.left = (parseInt(RGraph.Registry.Get('chart.tooltip').style.left) - leftDelta) + 'px' }", 200));RGraph.Registry.Get('chart.tooltip.timers').push(setTimeout("if(RGraph.Registry.Get('chart.tooltip')){ RGraph.Registry.Get('chart.tooltip').style.left = (parseInt(RGraph.Registry.Get('chart.tooltip').style.left) - leftDelta) + 'px' }", 225));RGraph.Registry.Get('chart.tooltip.timers').push(setTimeout("if(RGraph.Registry.Get('chart.tooltip')){ RGraph.Registry.Get('chart.tooltip').style.left = (parseInt(RGraph.Registry.Get('chart.tooltip').style.left) - leftDelta) + 'px' }", 250));RGraph.Registry.Get('chart.tooltip.timers').push(setTimeout("if(RGraph.Registry.Get('chart.tooltip')){ RGraph.Registry.Get('chart.tooltip').style.top = (parseInt(RGraph.Registry.Get('chart.tooltip').style.top) - topDelta) + 'px' }", 25));RGraph.Registry.Get('chart.tooltip.timers').push(setTimeout("if(RGraph.Registry.Get('chart.tooltip')){ RGraph.Registry.Get('chart.tooltip').style.top = (parseInt(RGraph.Registry.Get('chart.tooltip').style.top) - topDelta) + 'px' }", 50));RGraph.Registry.Get('chart.tooltip.timers').push(setTimeout("if(RGraph.Registry.Get('chart.tooltip')){ RGraph.Registry.Get('chart.tooltip').style.top = (parseInt(RGraph.Registry.Get('chart.tooltip').style.top) - topDelta) + 'px' }", 75));RGraph.Registry.Get('chart.tooltip.timers').push(setTimeout("if(RGraph.Registry.Get('chart.tooltip')){ RGraph.Registry.Get('chart.tooltip').style.top = (parseInt(RGraph.Registry.Get('chart.tooltip').style.top) - topDelta) + 'px' }", 100));RGraph.Registry.Get('chart.tooltip.timers').push(setTimeout("if(RGraph.Registry.Get('chart.tooltip')){ RGraph.Registry.Get('chart.tooltip').style.top = (parseInt(RGraph.Registry.Get('chart.tooltip').style.top) - topDelta) + 'px' }", 125));RGraph.Registry.Get('chart.tooltip.timers').push(setTimeout("if(RGraph.Registry.Get('chart.tooltip')){ RGraph.Registry.Get('chart.tooltip').style.top = (parseInt(RGraph.Registry.Get('chart.tooltip').style.top) - topDelta) + 'px' }", 150));RGraph.Registry.Get('chart.tooltip.timers').push(setTimeout("if(RGraph.Registry.Get('chart.tooltip')){ RGraph.Registry.Get('chart.tooltip').style.top = (parseInt(RGraph.Registry.Get('chart.tooltip').style.top) - topDelta) + 'px' }", 175));RGraph.Registry.Get('chart.tooltip.timers').push(setTimeout("if(RGraph.Registry.Get('chart.tooltip')){ RGraph.Registry.Get('chart.tooltip').style.top = (parseInt(RGraph.Registry.Get('chart.tooltip').style.top) - topDelta) + 'px' }", 200));RGraph.Registry.Get('chart.tooltip.timers').push(setTimeout("if(RGraph.Registry.Get('chart.tooltip')){ RGraph.Registry.Get('chart.tooltip').style.top = (parseInt(RGraph.Registry.Get('chart.tooltip').style.top) - topDelta) + 'px' }", 225));RGraph.Registry.Get('chart.tooltip.timers').push(setTimeout("if(RGraph.Registry.Get('chart.tooltip')){ RGraph.Registry.Get('chart.tooltip').style.top = (parseInt(RGraph.Registry.Get('chart.tooltip').style.top) - topDelta) + 'px' }", 250));RGraph.Registry.Get('chart.tooltip.timers').push(setTimeout("if(RGraph.Registry.Get('chart.tooltip')){ RGraph.Registry.Get('chart.tooltip').style.width = '" + (width * 0.1) + "px'; }", 25));RGraph.Registry.Get('chart.tooltip.timers').push(setTimeout("if(RGraph.Registry.Get('chart.tooltip')){ RGraph.Registry.Get('chart.tooltip').style.width = '" + (width * 0.2) + "px'; }", 50));RGraph.Registry.Get('chart.tooltip.timers').push(setTimeout("if(RGraph.Registry.Get('chart.tooltip')){ RGraph.Registry.Get('chart.tooltip').style.width = '" + (width * 0.3) + "px'; }", 75));RGraph.Registry.Get('chart.tooltip.timers').push(setTimeout("if(RGraph.Registry.Get('chart.tooltip')){ RGraph.Registry.Get('chart.tooltip').style.width = '" + (width * 0.4) + "px'; }", 100));RGraph.Registry.Get('chart.tooltip.timers').push(setTimeout("if(RGraph.Registry.Get('chart.tooltip')){ RGraph.Registry.Get('chart.tooltip').style.width = '" + (width * 0.5) + "px'; }", 125));RGraph.Registry.Get('chart.tooltip.timers').push(setTimeout("if(RGraph.Registry.Get('chart.tooltip')){ RGraph.Registry.Get('chart.tooltip').style.width = '" + (width * 0.6) + "px'; }", 150));RGraph.Registry.Get('chart.tooltip.timers').push(setTimeout("if(RGraph.Registry.Get('chart.tooltip')){ RGraph.Registry.Get('chart.tooltip').style.width = '" + (width * 0.7) + "px'; }", 175));RGraph.Registry.Get('chart.tooltip.timers').push(setTimeout("if(RGraph.Registry.Get('chart.tooltip')){ RGraph.Registry.Get('chart.tooltip').style.width = '" + (width * 0.8) + "px'; }", 200));RGraph.Registry.Get('chart.tooltip.timers').push(setTimeout("if(RGraph.Registry.Get('chart.tooltip')){ RGraph.Registry.Get('chart.tooltip').style.width = '" + (width * 0.9) + "px'; }", 225));RGraph.Registry.Get('chart.tooltip.timers').push(setTimeout("if(RGraph.Registry.Get('chart.tooltip')){ RGraph.Registry.Get('chart.tooltip').style.width = '" + width + "px'; }", 250));RGraph.Registry.Get('chart.tooltip.timers').push(setTimeout("if(RGraph.Registry.Get('chart.tooltip')){ RGraph.Registry.Get('chart.tooltip').style.height = '" + (height * 0.1) + "px'; }", 25));RGraph.Registry.Get('chart.tooltip.timers').push(setTimeout("if(RGraph.Registry.Get('chart.tooltip')){ RGraph.Registry.Get('chart.tooltip').style.height = '" + (height * 0.2) + "px'; }", 50));RGraph.Registry.Get('chart.tooltip.timers').push(setTimeout("if(RGraph.Registry.Get('chart.tooltip')){ RGraph.Registry.Get('chart.tooltip').style.height = '" + (height * 0.3) + "px'; }", 75));RGraph.Registry.Get('chart.tooltip.timers').push(setTimeout("if(RGraph.Registry.Get('chart.tooltip')){ RGraph.Registry.Get('chart.tooltip').style.height = '" + (height * 0.4) + "px'; }", 100));RGraph.Registry.Get('chart.tooltip.timers').push(setTimeout("if(RGraph.Registry.Get('chart.tooltip')){ RGraph.Registry.Get('chart.tooltip').style.height = '" + (height * 0.5) + "px'; }", 125));RGraph.Registry.Get('chart.tooltip.timers').push(setTimeout("if(RGraph.Registry.Get('chart.tooltip')){ RGraph.Registry.Get('chart.tooltip').style.height = '" + (height * 0.6) + "px'; }", 150));RGraph.Registry.Get('chart.tooltip.timers').push(setTimeout("if(RGraph.Registry.Get('chart.tooltip')){ RGraph.Registry.Get('chart.tooltip').style.height = '" + (height * 0.7) + "px'; }", 175));RGraph.Registry.Get('chart.tooltip.timers').push(setTimeout("if(RGraph.Registry.Get('chart.tooltip')){ RGraph.Registry.Get('chart.tooltip').style.height = '" + (height * 0.8) + "px'; }", 200));RGraph.Registry.Get('chart.tooltip.timers').push(setTimeout("if(RGraph.Registry.Get('chart.tooltip')){ RGraph.Registry.Get('chart.tooltip').style.height = '" + (height * 0.9) + "px'; }", 225));RGraph.Registry.Get('chart.tooltip.timers').push(setTimeout("if(RGraph.Registry.Get('chart.tooltip')){ RGraph.Registry.Get('chart.tooltip').style.height = '" + height + "px'; }", 250));RGraph.Registry.Get('chart.tooltip.timers').push(setTimeout("if(RGraph.Registry.Get('chart.tooltip')){ RGraph.Registry.Get('chart.tooltip').innerHTML = RGraph.Registry.Get('chart.tooltip').__text__; }", 250));RGraph.Registry.Get('chart.tooltip.timers').push(setTimeout("if(RGraph.Registry.Get('chart.tooltip')){ RGraph.Registry.Get('chart.tooltip').style.boxShadow = 'rgba(96,96,96,0.5) 3px 3px 3px'; }", 250));RGraph.Registry.Get('chart.tooltip.timers').push(setTimeout("if(RGraph.Registry.Get('chart.tooltip')){ RGraph.Registry.Get('chart.tooltip').style.MozBoxShadow = 'rgba(96,96,96,0.5) 3px 3px 3px'; }", 250));RGraph.Registry.Get('chart.tooltip.timers').push(setTimeout("if(RGraph.Registry.Get('chart.tooltip')){ RGraph.Registry.Get('chart.tooltip').style.WebkitBoxShadow = 'rgba(96,96,96,0.5) 3px 3px 3px'; }", 250));RGraph.Registry.Get('chart.tooltip.timers').push(setTimeout("if(RGraph.Registry.Get('chart.tooltip')){ RGraph.Registry.Get('chart.tooltip').style.borderRadius = '5px'; }", 250));RGraph.Registry.Get('chart.tooltip.timers').push(setTimeout("if(RGraph.Registry.Get('chart.tooltip')){ RGraph.Registry.Get('chart.tooltip').style.MozBorderRadius = '5px'; }", 250));RGraph.Registry.Get('chart.tooltip.timers').push(setTimeout("if(RGraph.Registry.Get('chart.tooltip')){ RGraph.Registry.Get('chart.tooltip').style.WebkitBorderRadius = '5px'; }", 250));} else if(placementLeft && effect == 'fade'){
obj.style.top = (y - height) + 'px';} else if(effect != 'fade' && effect != 'expand'){
alert('[COMMON] Unknown tooltip effect: ' + effect);}
setTimeout("if(RGraph.Registry.Get('chart.tooltip')){ RGraph.Registry.Get('chart.tooltip').style.opacity = 0.1; RGraph.Registry.Get('chart.tooltip').style.border = '1px solid rgba(96,96,96,0.2)'; }", 25);setTimeout("if(RGraph.Registry.Get('chart.tooltip')){ RGraph.Registry.Get('chart.tooltip').style.opacity = 0.2; RGraph.Registry.Get('chart.tooltip').style.border = '1px solid rgba(96,96,96,0.2)'; }", 50);setTimeout("if(RGraph.Registry.Get('chart.tooltip')){ RGraph.Registry.Get('chart.tooltip').style.opacity = 0.3; RGraph.Registry.Get('chart.tooltip').style.border = '1px solid rgba(96,96,96,0.2)'; }", 75);setTimeout("if(RGraph.Registry.Get('chart.tooltip')){ RGraph.Registry.Get('chart.tooltip').style.opacity = 0.4; RGraph.Registry.Get('chart.tooltip').style.border = '1px solid rgba(96,96,96,0.2)'; }", 100);setTimeout("if(RGraph.Registry.Get('chart.tooltip')){ RGraph.Registry.Get('chart.tooltip').style.opacity = 0.5; RGraph.Registry.Get('chart.tooltip').style.border = '1px solid rgba(96,96,96,0.2)'; }", 125);setTimeout("if(RGraph.Registry.Get('chart.tooltip')){ RGraph.Registry.Get('chart.tooltip').style.opacity = 0.6; RGraph.Registry.Get('chart.tooltip').style.border = '1px solid rgba(96,96,96,0.2)'; }", 150);setTimeout("if(RGraph.Registry.Get('chart.tooltip')){ RGraph.Registry.Get('chart.tooltip').style.opacity = 0.7; RGraph.Registry.Get('chart.tooltip').style.border = '1px solid rgba(96,96,96,0.4)'; }", 175);setTimeout("if(RGraph.Registry.Get('chart.tooltip')){ RGraph.Registry.Get('chart.tooltip').style.opacity = 0.8; RGraph.Registry.Get('chart.tooltip').style.border = '1px solid rgba(96,96,96,0.6)'; }", 200);setTimeout("if(RGraph.Registry.Get('chart.tooltip')){ RGraph.Registry.Get('chart.tooltip').style.opacity = 0.9; RGraph.Registry.Get('chart.tooltip').style.border = '1px solid rgba(96,96,96,0.8)'; }", 225);setTimeout("if(RGraph.Registry.Get('chart.tooltip')){ RGraph.Registry.Get('chart.tooltip').style.opacity = 1; RGraph.Registry.Get('chart.tooltip').style.border = '1px solid rgb(96,96,96'; }", 250);document.body.onmousedown = function ()
{
var tooltip = RGraph.Registry.Get('chart.tooltip');if(tooltip){
tooltip.style.display = 'none';tooltip.style.visibility = 'hidden';RGraph.Registry.Set('chart.tooltip', null);RGraph.Redraw();}
}
document.body.onmouseup = document.body.onmousedown;document.body.onclick = document.body.onmousedown;window.onresize = function ()
{
var tooltip = RGraph.Registry.Get('chart.tooltip');if(tooltip){
tooltip.style.display = 'none';                
tooltip.style.visibility = 'hidden';RGraph.Registry.Set('chart.tooltip', null);RGraph.Clear(canvas);canvas.__object__.Draw();}
}
RGraph.Registry.Set('chart.tooltip', obj);}
RGraph.Register = function (obj)
{
var key = obj.id + '_' + obj.type;RGraph.objects[key] = obj;}
RGraph.Redraw = function ()
{
for (i in RGraph.objects){
if(typeof(i) == 'string' && typeof(RGraph.objects[i]) == 'object')  {
if(!arguments[0] || arguments[0] != RGraph.objects[i].id){
RGraph.Clear(RGraph.objects[i].canvas);RGraph.objects[i].Draw();}
}
}
}
RGraph.pr = function (obj)
{
var str = '';var indent = (arguments[2] ? arguments[2] : '');switch (typeof(obj)){
case 'number':
if(indent == ''){
str+= 'Number: '
}
str += String(obj);break;case 'string':
if(indent == ''){
str+= 'String (' + obj.length + '):'
}
str += '"' + String(obj) + '"';break;case 'object':
if(obj == null){
str += 'null';break;}
str += 'Object \n' + indent + '(\n';for (i=0; i<obj.length; ++i){
str += indent + '  ' + i + ' => ' + RGraph.pr(obj[i], true, indent + '\t') + '\n';}
var str = str + indent + ')';break;case 'function':
str += obj;break;case 'boolean':
str += 'Boolean: ' + (obj ? 'true' : 'false');break;}
if(arguments[1]){
return str;} else {
alert(str);}
}
RGraph.Registry.Set = function (name, value)
{
RGraph.Registry.store[name] = value;return value;}
RGraph.Registry.Get = function (name)
{
return RGraph.Registry.store[name];}
RGraph.background.Draw = function (obj)
{
var canvas = obj.canvas;var context = obj.context;var height = 0;var gutter = obj.Get('chart.gutter');if(obj.Get('chart.variant') == '3d'){
context.save();context.translate(10, -5);}
obj.context.beginPath();context.fillStyle = obj.Get('chart.background.barcolor1');height = (obj.canvas.height - obj.Get('chart.gutter'));for (var i=gutter; i < height ; i+=80){
obj.context.fillRect(gutter, i, obj.canvas.width - (gutter * 2), Math.min(40, obj.canvas.height - gutter - i) );}
context.fillStyle = obj.Get('chart.background.barcolor2');height = (obj.canvas.height - gutter);for (var i= (40 + gutter); i < height; i+=80){
obj.context.fillRect(gutter, i, obj.canvas.width - (gutter * 2), i + 40 > (obj.canvas.height - gutter) ? obj.canvas.height - (gutter + i) : 40);}
context.stroke();if(obj.Get('chart.background.grid')){
context.beginPath();context.lineWidth = obj.Get('chart.background.grid.width') ? obj.Get('chart.background.grid.width') : 1;context.strokeStyle = obj.Get('chart.background.grid.color');if(obj.Get('chart.background.grid.hlines')){
height = (canvas.height - gutter)
for (y=gutter; y < height; y+=obj.Get('chart.background.grid.hsize')){
context.moveTo(gutter, y);context.lineTo(canvas.width - gutter, y);}
}
if(obj.Get('chart.background.grid.vlines')){
var width = (canvas.width - gutter)
for (x=gutter; x<=width; x+=obj.Get('chart.background.grid.vsize')){
context.moveTo(x, gutter);context.lineTo(x, obj.canvas.height - gutter);}
}
if(obj.Get('chart.background.grid.border')){
context.strokeStyle = obj.Get('chart.background.grid.color');context.strokeRect(gutter, gutter, canvas.width - (2 * gutter), canvas.height - (2 * gutter));}
}
context.stroke();if(obj.Get('chart.variant') == '3d'){
context.restore();}
if( typeof(obj.Get('chart.title')) == 'string'){
if(obj.type == 'gantt'){
gutter /= 2;}
RGraph.DrawTitle(canvas, obj.Get('chart.title'), gutter, null, obj.Get('chart.text.size') + 2);}
context.stroke();}
RGraph.GetDays = function (obj)
{
var year = obj.getFullYear();var days = obj.getDate();var month = obj.getMonth();if(month == 0) return days;if(month >= 1) days += 31; 
if(month >= 2) days += 28;if(year >= 2008 && year % 4 == 0) days += 1;if(month >= 3) days += 31;if(month >= 4) days += 30;if(month >= 5) days += 31;if(month >= 6) days += 30;if(month >= 7) days += 31;if(month >= 8) days += 31;if(month >= 9) days += 30;if(month >= 10) days += 31;if(month >= 11) days += 30;return days;}
RGraph.DrawKey = function (obj, key, colors)
{
var canvas = obj.canvas;var context = obj.context;context.lineWidth = 1;context.beginPath();var keypos = obj.Get('chart.key.position');var textsize = obj.Get('chart.text.size');var gutter = obj.Get('chart.gutter');if(keypos && keypos == 'gutter'){
var length = 0;var key = obj.Get('chart.key');if(obj.type == 'pie' && obj.Get('chart.align') == 'left'){
var centerx = obj.radius + obj.Get('chart.gutter');} else if(obj.type == 'pie' && obj.Get('chart.align') == 'right'){
var centerx = obj.canvas.width - obj.radius - obj.Get('chart.gutter');} else {
var centerx = canvas.width / 2;}
context.font = obj.Get('chart.text.size') + 'pt ' + obj.Get('chart.text.font');for (i=0; i<key.length; ++i){
length += context.measureText(key[i]).width;length += 20;length += 10;}
var start = centerx - (length / 2);for (i=0; i<key.length; ++i){
start += 10;context.fillStyle = obj.Get('chart.colors')[i];context.fillRect(start + 9, gutter - 5 - textsize, textsize, textsize + 1);context.stroke();context.fill();context.fillStyle = obj.Get('chart.text.color');RGraph.Text(context, obj.Get('chart.text.font'), textsize,
start + 25,
gutter - 6 - textsize,
key[i],
'top');context.fill();start += context.measureText(key[i]).width + 15;}
} else if(keypos && keypos == 'graph'){
context.font = textsize + 'pt ' + obj.Get('chart.text.font');var width = 0;for (i=0; i<key.length; ++i){
width = Math.max(width, context.measureText(key[i]).width);}
width += 32;if(obj.Get('chart.key.shadow')){
context.shadowColor = '#666';context.shadowBlur = 3;context.shadowOffsetX = 2;context.shadowOffsetY = 2;}
context.beginPath();context.fillStyle = obj.Get('chart.key.background');context.strokeStyle = 'black';var xpos = canvas.width - width - gutter;if(obj.Get('chart.yaxispos') == 'right'){
xpos -= (obj.canvas.width - (obj.Get('chart.gutter') * 2));xpos += width + 6;}
if(arguments[3] != false){
context.strokeRect(xpos, gutter + 5, width - 5, 5 + ( (textsize + 5) * key.length));context.fillRect(xpos, gutter + 5, width - 5, 5 + ( (textsize + 5) * key.length) );}
context.shadowColor = 'rgba(0,0,0,0)';for (var i=key.length - 1; i>=0; i--){
var j = Number(i) + 1;context.fillStyle = colors[i];context.fillRect(xpos + 5, 5 + gutter + (5 * j) + (textsize * j) - (textsize), textsize, textsize);context.fill();context.stroke();context.fillStyle = obj.Get('chart.text.color');RGraph.Text(context, obj.Get('chart.text.font'), textsize, xpos + 21, gutter + (5 * j) + (textsize * j) + 4, key[i]);}
} else {
alert('[COMMON] (' + obj.id + ') Unknown key position: ' + keypos);}
}
function pd(variable)
{
RGraph.pr(variable);}
RGraph.array_clone = function (obj)
{
if(obj == null || typeof(obj) != 'object'){
return obj;}
var temp = [];for(var i=0;i<obj.length; ++i){
temp[i] = RGraph.array_clone(obj[i]);}
return temp;}
RGraph.array_reverse = function (arr)
{
var newarr = [];for (var i=arr.length - 1; i>=0; i--){
newarr.push(arr[i]);}
return newarr;}
RGraph.number_format = function (num)
{
var i;var prepend = arguments[1] ? String(arguments[1]) : '';var append = arguments[2] ? String(arguments[2]) : '';var output = '';var decimal = '';RegExp.$1 = '';if(String(num).indexOf('e') > 0){
return String(prepend + String(num) + append);}
num = String(num);if(num.indexOf('.') > 0){
num = num.replace(/\.(.*)/, '');decimal = RegExp.$1;}
var seperator = ',';var foundPoint;for (i=(num.length - 1),j=0; i>=0; j++,i--){
var char = num.charAt(i);if( j % 3 == 0 && j != 0){
output += seperator;}
output += char;}
var rev = output;output = '';for (i=(rev.length - 1); i>=0; i--){
output += rev.charAt(i);}
output = output.replace(/^-,/, '-');if(decimal.length){
output =  output + '.' + decimal;decimal = '';RegExp.$1 = '';}
if(output.charAt(0) == '-'){
output *= -1;prepend = '-' + prepend;}
return prepend + output + append;}
RGraph.Contextmenu = function (canvas, menuitems, e)
{
e = RGraph.FixEventObject(document.all ? event : e);if(RGraph.Registry.Get('chart.contextmenu')){
RGraph.HideContext();}
RGraph.HidePalette();canvas.__object__.Set('chart.mousedown', false)
var x = e.pageX;var y = e.pageY;var div = document.createElement('div');var bg = document.createElement('div');div.className = 'RGraph_contextmenu';div.__canvas__ = canvas; 
div.style.position = 'absolute';div.style.left = 0;div.style.top = 0;div.style.border = '1px solid black';div.style.backgroundColor = '#fff';div.style.MozBoxShadow = '3px 3px 3px rgba(0,0,0,0.5)';div.style.WebkitBoxShadow = '3px 3px 3px rgba(0,0,0,0.5)';div.style.opacity = 0;bg.className = 'RGraph_contextmenu_background';bg.style.position = 'absolute';bg.style.backgroundColor = '#ccc';bg.style.borderRight = '1px solid #aaa';bg.style.top = 0;bg.style.left = 0;bg.style.width = '18px';bg.style.opacity = 0;bg.style.height = '100%';div = document.body.appendChild(div);bg = div.appendChild(bg);for (i=0; i<menuitems.length; ++i){
var menuitem = document.createElement('div');menuitem.__canvas__ = canvas;menuitem.className = 'RGraph_contextmenu_item';if(menuitems[i]){
menuitem.style.padding = '2px 5px 2px 23px';menuitem.style.fontFamily = 'Arial';menuitem.style.fontSize = '10pt';menuitem.style.fontWeight = 'normal';menuitem.innerHTML = menuitems[i][0];if(menuitems[i][1]){
if(menuitem.addEventListener){
menuitem.addEventListener("mouseover", function (e){e.target.style.backgroundColor = '#eee'; e.target.style.cursor = 'pointer';}, false);menuitem.addEventListener("mouseout", function (e){e.target.style.backgroundColor = 'white'; e.target.style.cursor = null;}, false);} else  {
menuitem.attachEvent("onmouseover", function (){event.srcElement.style.backgroundColor = '#eee'; event.srcElement.style.cursor = 'hand'}, false);menuitem.attachEvent("onmouseout", function (){event.srcElement.style.backgroundColor = 'white'; event.target.style.cursor = null;}, false);}
} else {
if(menuitem.addEventListener){
menuitem.addEventListener("mouseover", function (e){e.target.style.cursor = 'default';}, false);menuitem.addEventListener("mouseout", function (e){e.target.style.cursor = null;}, false);} else  {
menuitem.attachEvent("onmouseover", function (){event.srcElement.style.cursor = 'default'}, false);menuitem.attachEvent("onmouseout", function (){event.target.style.cursor = null;}, false);}
}
} else {
menuitem.style.borderBottom = '1px solid #ddd';menuitem.style.marginLeft = '25px';}
div.appendChild(menuitem);if(menuitems[i] && menuitems[i][1]){
if(document.all){
menuitem.attachEvent('onclick', menuitems[i][1]);} else {
menuitem.addEventListener('click', menuitems[i][1], false);}
}
}
div.style.width = div.offsetWidth + 'px';if(x + div.offsetWidth > document.body.offsetWidth){
x -= div.offsetWidth;}
div.style.left = x + 'px';div.style.top = y + 'px';setTimeout("if(obj = RGraph.Registry.Get('chart.contextmenu')) obj.style.opacity = 0.2", 50);setTimeout("if(obj = RGraph.Registry.Get('chart.contextmenu')) obj.style.opacity = 0.4", 100);setTimeout("if(obj = RGraph.Registry.Get('chart.contextmenu')) obj.style.opacity = 0.6", 150);setTimeout("if(obj = RGraph.Registry.Get('chart.contextmenu')) obj.style.opacity = 0.8", 200);setTimeout("if(obj = RGraph.Registry.Get('chart.contextmenu')) obj.style.opacity = 1", 250);setTimeout("if(obj = RGraph.Registry.Get('chart.contextmenu.bg')) obj.style.opacity = 0.2", 50);setTimeout("if(obj = RGraph.Registry.Get('chart.contextmenu.bg')) obj.style.opacity = 0.4", 100);setTimeout("if(obj = RGraph.Registry.Get('chart.contextmenu.bg')) obj.style.opacity = 0.6", 150);setTimeout("if(obj = RGraph.Registry.Get('chart.contextmenu.bg')) obj.style.opacity = 0.8", 200);setTimeout("if(obj = RGraph.Registry.Get('chart.contextmenu.bg')) obj.style.opacity = 1", 250);RGraph.Registry.Set('chart.contextmenu', div);RGraph.Registry.Set('chart.contextmenu.bg', bg);RGraph.Registry.Get('chart.contextmenu').oncontextmenu = function (){return false;};RGraph.Registry.Get('chart.contextmenu.bg').oncontextmenu = function (){return false;};if(navigator.userAgent.indexOf('Opera') == -1){
canvas.onclick = function ()
{
RGraph.HideContext();}
}
window.onclick = function (e)
{
RGraph.Redraw();RGraph.HideContext();if(e.target.onclick && e.button == 0){
e.target.onclick(e);}
}
window.onresize = function (){RGraph.HideContext();}
e.stopPropagation = true;e.cancelBubble = true;return false;}
RGraph.HideContext = function ()
{
var cm = RGraph.Registry.Get('chart.contextmenu');var cmbg = RGraph.Registry.Get('chart.contextmenu.bg');if(cm){
cm.style.visibility = 'hidden';cm.style.display = 'none';RGraph.Registry.Set('chart.contextmenu', null);cmbg.style.visibility = 'hidden';cmbg.style.display = 'none';RGraph.Registry.Set('chart.contextmenu.bg', null);}
}
RGraph.ShowContext = function (obj)
{
RGraph.HidePalette();if(obj.Get('chart.contextmenu') && obj.Get('chart.contextmenu').length){
if((navigator.userAgent.indexOf('Opera') == -1 && navigator.userAgent.indexOf('Safari') == -1) || navigator.userAgent.indexOf('Chrome') != -1){
obj.canvas.oncontextmenu = function (e)
{
if(e.ctrlKey) return true;RGraph.Contextmenu(obj.canvas, obj.Get('chart.contextmenu'), e);return false;}
} else {
obj.canvas.addEventListener('click', function (e)
{
if(e.ctrlKey) return true;if(!RGraph.Registry.Get('chart.contextmenu')){
RGraph.Contextmenu(obj.canvas, obj.Get('chart.contextmenu'), e);}
}, false);}
}
}
RGraph.DrawBars = function (obj)
{
var hbars = obj.Get('chart.background.hbars');obj.context.beginPath();for (i=0; i<hbars.length; ++i){
if(hbars[i][1] == null){
hbars[i][1] = obj.max;} else if(hbars[i][0] + hbars[i][1] > obj.max){
hbars[i][1] = obj.max - hbars[i][0];}
if(Math.abs(hbars[i][1]) > obj.max){
hbars[i][1] = -1 * obj.max;}
if(Math.abs(hbars[i][0]) > obj.max){
hbars[i][0] = obj.max;}
if(hbars[i][0] + hbars[i][1] < (-1 * obj.max) ){
hbars[i][1] = -1 * (obj.max + hbars[i][0]);}
var ystart = (obj.grapharea - ((hbars[i][0] / obj.max) * obj.grapharea));var height = (Math.min(hbars[i][1], obj.max - hbars[i][0]) / obj.max) * obj.grapharea;if(obj.Get('chart.xaxispos') == 'center'){
ystart /= 2;height /= 2;}
ystart += obj.Get('chart.gutter')
var x = obj.Get('chart.gutter');var y = ystart - height;var w = obj.canvas.width - (2 * obj.Get('chart.gutter'));var h = height;if(navigator.userAgent.indexOf('Opera') != -1 && obj.Get('chart.xaxispos') == 'center' && h < 0){
h *= -1;y = y - h;}
obj.context.fillStyle = hbars[i][2];obj.context.fillRect(x, y, w, h);}
obj.context.fill();}
RGraph.DrawInGraphLabels = function (obj)
{
var canvas = obj.canvas;var context = obj.context;var labels = obj.Get('chart.labels.ingraph');RGraph.NoShadow(obj);if(labels && labels.length > 0){
for (var i=0; i<labels.length; ++i){
if(labels[i]){
var coords = obj.coords[i];if(coords && coords.length > 0){
var x = (obj.type == 'bar' ? coords[0] + (coords[2] / 2) : coords[0]);var y = (obj.type == 'bar' ? coords[1] + (coords[3] / 2) : coords[1]) - 5;context.beginPath();context.fillStyle = 'black';context.strokeStyle = '#666';if(obj.type == 'bar'){
if(obj.Get('chart.variant') == 'dot'){
context.moveTo(x, y - 15);context.lineTo(x, y - 25);} else if(obj.Get('chart.variant') == 'arrow'){
context.moveTo(x, y - 15);context.lineTo(x, y - 25);} else {
context.arc(x, y, 1, 0, 6.28, 0);context.moveTo(x, y);context.lineTo(x, y - 25);}
} else if(obj.type == 'line'){
context.moveTo(x, y - 5);context.lineTo(x, y - 25);context.moveTo(x, y);context.lineTo(x - 3, y - 7);context.lineTo(x + 3, y - 7);context.closePath();}
context.stroke();context.fill();var width = context.measureText(labels[i]).width;RGraph.Text(context, 'Verdana', obj.Get('chart.text.size'), x, y - 25, String(labels[i]), 'bottom', 'center', null, null, '#fff');context.fill();}
}
}
}
}
RGraph.FixEventObject = function (e)
{
if(document.all){
e.pageX = (event.clientX + document.body.scrollLeft);e.pageY = (event.clientY + document.body.scrollTop);e.target = event.srcElement;}
if(typeof(e.offsetX) == 'undefined' && typeof(e.offsetY) == 'undefined'){
var coords = RGraph.getMouseXY(e);e.offsetX = coords[0];e.offsetY = coords[1];}
return e;}
RGraph.DrawCrosshairs = function (obj)
{
if(obj.Get('chart.crosshairs')){
var canvas = obj.canvas;var context = obj.context;if(obj.Get('chart.tooltips') && obj.Get('chart.tooltips').length > 0){
alert('[' + obj.type.toUpperCase() + '] Sorry - you cannot have crosshairs enabled with tooltips! Turning off crosshairs...');obj.Set('chart.crosshairs', false);return;}
canvas.onmousemove = function (e)
{
var e = RGraph.FixEventObject(document.all ? event : e);var canvas = obj.canvas;var context = obj.context;var gutter = obj.Get('chart.gutter');var width = canvas.width;var height = canvas.height;var mouseCoords = RGraph.getMouseXY(e);var x = mouseCoords[0];var y = mouseCoords[1];RGraph.Clear(canvas);obj.Draw();if(   x > gutter

&& y > gutter
&& x < (width - gutter)
&& y < (height - gutter)
){
context.lineWidth = 1;context.beginPath();context.strokeStyle = obj.Get('chart.crosshairs.color');context.moveTo(x, gutter);context.lineTo(x, height - gutter);context.moveTo(gutter, y);context.lineTo(width - gutter, y);context.stroke();}
}
}
}
RGraph.Annotate = function (obj)
{
if(obj.Get('chart.annotatable')){
var canvas = obj.canvas;var context = obj.context;canvas.onmousedown = function (e)
{
if(e.button == 0){
e.target.__object__.Set('chart.mousedown', true);var context = e.target.__object__.canvas.getContext('2d');context.beginPath();var coords = RGraph.getMouseXY(e);var x = coords[0];var y = coords[1];RGraph.Registry.Set('annotate.actions', [obj.Get('chart.annotate.color')]);context.strokeStyle = obj.Get('chart.annotate.color');context.moveTo(x, y);context.lineWidth = 1;RGraph.Registry.Set('started.annotating', false);}
return false;}
window.onmouseup = function (e)
{
var tags = document.getElementsByTagName('canvas');for (var i=0; i<tags.length; ++i){
if(tags[i].__object__){
tags[i].__object__.Set('chart.mousedown', false);}
}
if(RGraph.Registry.Get('annotate.actions') && RGraph.Registry.Get('annotate.actions').length > 0 && window.localStorage){
var id = '__rgraph_annotations_' + e.target.id + '__';var annotations = window.localStorage[id] ? window.localStorage[id] + '|' : '';annotations += RGraph.Registry.Get('annotate.actions');window.localStorage[id] = annotations;}
RGraph.Registry.Set('annotate.actions', []);}
canvas.onmouseup = window.onmouseup;canvas.onmouseout = window.onmouseup;canvas.onmousemove = function (e)
{
var e = RGraph.FixEventObject(e);var obj = e.target.__object__;var coords = RGraph.getMouseXY(e);var x = coords[0];var y = coords[1];var gutter = obj.Get('chart.gutter');var width = canvas.width;var height = canvas.height;obj.context.lineWidth = 1;if(
x > gutter && x < (width - gutter)
&& y > gutter && y < (height - gutter)
){
canvas.style.cursor = 'crosshair';if(obj.Get('chart.mousedown')){
if(
x > gutter && x < (width - gutter)

&& y > gutter && y < (height - gutter)
){
if( (obj.type != 'hbar' && obj.type != 'gantt') || x > (3 * gutter)){
if(RGraph.Registry.Get('started.annotating') == false){
context.moveTo(x, y);RGraph.Registry.Set('started.annotating', true)
}
context.lineTo(x, y);RGraph.Registry.Set('annotate.actions', RGraph.Registry.Get('annotate.actions') + '|' + x + ',' + y);context.stroke();}
} else {
context.moveTo(x, y);}
}
} else {
canvas.style.cursor = 'default';}
}
if(!arguments[1]){
RGraph.ReplayAnnotations(obj);}
}
}
RGraph.Showpalette = function (e)
{
var isSafari = navigator.userAgent.indexOf('Safari') ? true : false;e = RGraph.FixEventObject(document.all ? event : e);var canvas = e.target.parentNode.__canvas__;var context = canvas.getContext('2d');var obj = canvas.__object__;var div = document.createElement('DIV');var coords = RGraph.getMouseXY(e);div.__object__ = obj;div.className = 'RGraph_palette';div.style.position = 'absolute';div.style.backgroundColor = 'white';div.style.border = '1px solid black';div.style.left = 0;div.style.top = 0;div.style.padding = '3px';div.style.paddingBottom = 0;div.style.paddingRight = 0;div.style.opacity = 0;div.style.WebkitBoxShadow = 'rgba(96,96,96,0.5) 3px 3px 3px';div.style.MozBoxShadow = 'rgba(96,96,96,0.5) 3px 3px 3px';div.style.filter = 'progid:DXImageTransform.Microsoft.Shadow(color=#666666,direction=135)';var common_css = 'padding: 1px; display: inline; display: inline-block; width: 15px; height: 15px; margin-right: 3px; cursor: ' + (document.all ? 'hand;' : 'pointer; ');var common_mouseover = ' onmouseover="this.style.border = \'1px black solid\'; this.style.padding = 0"';var common_mouseout = ' onmouseout="this.style.border = 0; this.style.padding = \'1px\'" ';var safari_css = isSafari ? 'margin-bottom: 3px' : '';var str = '';var colors = ['red', 'blue', 'green', 'black', 'yellow', 'magenta', 'pink', 'cyan', 'purple', '#ddf', 'gray', '#36905c'];for (i=0; i<colors.length; ++i){
str = str + '<div ' + common_mouseover + common_mouseout + ' style="background-color: ' + colors[i] + '; ' + common_css + safari_css + '" onclick="this.parentNode.__object__.Set(\'chart.annotate.color\', this.style.backgroundColor); this.parentNode.style.display = \'none\'">&nbsp;</div>';if(i == 5){
str += '<br />';}
}
div.innerHTML = str;document.body.appendChild(div);div.style.width = (div.offsetWidth - 5) + 'px';div.style.height = (div.offsetHeight - 5) + 'px';div.style.left = Math.max(0, e.pageX - div.offsetWidth - 2) + 'px';div.style.top = (e.pageY - div.offsetHeight - 2) + 'px';RGraph.Registry.Set('palette', div);setTimeout("RGraph.Registry.Get('palette').style.opacity = 0.2", 50);setTimeout("RGraph.Registry.Get('palette').style.opacity = 0.4", 100);setTimeout("RGraph.Registry.Get('palette').style.opacity = 0.6", 150);setTimeout("RGraph.Registry.Get('palette').style.opacity = 0.8", 200);setTimeout("RGraph.Registry.Get('palette').style.opacity = 1", 250);RGraph.HideContext();window.onclick = function ()
{
RGraph.HidePalette();}
e.cancelBubble = true;e.stopPropagation = true;}
RGraph.HidePalette = function ()
{
var div = RGraph.Registry.Get('palette');if(typeof(div) == 'object' && div){
div.style.visibility = 'hidden';div.style.display = 'none';RGraph.Registry.Set('palette', null);}
}
RGraph.ClearAnnotations = function (id)
{
if(window.localStorage && window.localStorage['__rgraph_annotations_' + id + '__'] && window.localStorage['__rgraph_annotations_' + id + '__'].length){
window.localStorage['__rgraph_annotations_' + id + '__'] = [];}
}
RGraph.ReplayAnnotations = function (obj)
{
if(!window.localStorage){
return;}
var context = obj.context;var annotations = window.localStorage['__rgraph_annotations_' + obj.id + '__'];var i, len, move, coords;context.lineWidth = 2;if(annotations && annotations.length){
annotations = annotations.split('|');} else {
return;}
for (i=0, len=annotations.length; i<len; ++i){
if(!annotations[i].match(/^[0-9]+,[0-9]+$/)){
context.stroke();context.beginPath();context.strokeStyle = annotations[i];move = true;continue;}
coords = annotations[i].split(',');if(move){
context.moveTo(coords[0], coords[1]);move = false;} else {
context.lineTo(coords[0], coords[1]);}
}
context.stroke();}
RGraph.rtrim = function (str)
{
return str.replace(/( |\n|\r|\t)+$/, '');}
RGraph.Draw3DAxes = function (obj)
{
var gutter = obj.Get('chart.gutter');var context = obj.context;var canvas = obj.canvas;context.strokeStyle = '#aaa';context.fillStyle = '#ddd';context.beginPath();context.moveTo(gutter, gutter);context.lineTo(gutter + 10, gutter - 5);context.lineTo(gutter + 10, canvas.height - gutter - 5);context.lineTo(gutter, canvas.height - gutter);context.closePath();context.stroke();context.fill();context.beginPath();context.moveTo(gutter, canvas.height - gutter);context.lineTo(gutter + 10, canvas.height - gutter - 5);context.lineTo(canvas.width - gutter + 10,  canvas.height - gutter - 5);context.lineTo(canvas.width - gutter, canvas.height - gutter);context.closePath();context.stroke();context.fill();}
RGraph.NoShadow = function (obj)
{
obj.context.shadowColor = 'rgba(0,0,0,0)';obj.context.shadowBlur = 0;obj.context.shadowOffsetX = 0;obj.context.shadowOffsetY = 0;}
RGraph.Zoom = function (e)
{
e = RGraph.FixEventObject(document.all ? event : e);var canvas = e.target.__canvas__;var context = canvas.getContext('2d');var obj = canvas.__object__;var tmp = canvas;var x = 0;var y = 0;var factor = obj.Get('chart.zoom.factor') - 1;while (tmp != document.body){
x += tmp.offsetLeft;y += tmp.offsetTop;tmp = tmp.offsetParent;}
var img = document.createElement('img');img.style.border = '2px dashed gray';img.style.width = canvas.width + 'px';img.style.height = canvas.height + 'px';img.style.position = 'absolute';img.style.left = x + 'px';img.style.top = y + 'px';img.style.backgroundColor = 'white';img.style.opacity = obj.Get('chart.zoom.fade.in') ? 0 : 1;img.src = canvas.toDataURL();document.body.appendChild(img);RGraph.Registry.Set('chart.zoomedimage', img);img.onclick = function (e)
{
e.cancelBubble = true;e.stopPropagation = true;return false;};
__HideZoomedCanvas__ = function ()
{
if(obj.Get('chart.zoom.fade.out')){
for (var i=10,j=1; i>=0; --i, ++j){
setTimeout("RGraph.Registry.Get('chart.zoomedimage').style.opacity = " + String(i / 10), j * 50);}
}
setTimeout("RGraph.Registry.Get('chart.zoomedimage').style.display = 'none'", obj.Get('chart.zoom.fade.out') ? 250 : 0);}
setTimeout(function (){window.onclick = __HideZoomedCanvas__;}, 1);var width = parseInt(canvas.width);var height = parseInt(canvas.height);var frames = obj.Get('chart.zoom.frames');var delay = obj.Get('chart.zoom.delay');if(obj.Get('chart.zoom.hdir') == 'center'){
for (var i=1; i<=frames; ++i){
var newWidth = width * factor * (i/frames) + width;var rightHandEdge = x + canvas.width;var newLeft = (x + (canvas.width / 2)) - (newWidth / 2);setTimeout("RGraph.Registry.Get('chart.zoomedimage').style.width = '" + String(newWidth) + "px'; RGraph.Registry.Get('chart.zoomedimage').style.left = '" + newLeft + "px'", i * delay);}
} else if(obj.Get('chart.zoom.hdir') == 'left'){            
for (var i=1; i<=frames; ++i){
var newWidth = width * factor * (i/frames) + width;var rightHandEdge = x + canvas.width;var newLeft = rightHandEdge - newWidth;setTimeout("RGraph.Registry.Get('chart.zoomedimage').style.width = '" + String(newWidth) + "px'; RGraph.Registry.Get('chart.zoomedimage').style.left = '" + newLeft + "px'", i * delay);}
} else {
for (var i=1; i<=frames; ++i){
var newWidth = width * factor * (i/frames) + width;setTimeout("RGraph.Registry.Get('chart.zoomedimage').style.width = '" + String(newWidth) + "px'", i * delay);}
}
if(obj.Get('chart.zoom.vdir') == 'up'){
for (var i=1; i<=frames; ++i){
var newHeight = (height * factor * (i/frames)) + height;var bottomEdge = y + canvas.height;var newTop = bottomEdge - newHeight;setTimeout("RGraph.Registry.Get('chart.zoomedimage').style.height = '" + String(newHeight) + "px'; RGraph.Registry.Get('chart.zoomedimage').style.top = '" + newTop + "px'", i * delay);}
} else if(obj.Get('chart.zoom.vdir') == 'center'){
for (var i=1; i<=frames; ++i){
var newHeight = (height * factor * (i/frames)) + height;var bottomEdge = (y + (canvas.height / 2)) + (newHeight / 2);var newTop = bottomEdge - newHeight;setTimeout("RGraph.Registry.Get('chart.zoomedimage').style.height = '" + String(newHeight) + "px'; RGraph.Registry.Get('chart.zoomedimage').style.top = '" + newTop + "px'", i * delay);}
} else {
for (var i=1; i<=frames; ++i){
setTimeout("RGraph.Registry.Get('chart.zoomedimage').style.height = '" + String(height * factor * (i/frames) + height) + "px'", i * delay);}
}
if(obj.Get('chart.zoom.fade.in')){
for (var i=1; i<=frames; ++i){
setTimeout("RGraph.Registry.Get('chart.zoomedimage').style.opacity = " + String(i / frames), i * delay);}
}
if(obj.Get('chart.zoom.shadow')){
for (var i=1; i<=frames; ++i){
setTimeout("RGraph.Registry.Get('chart.zoomedimage').style.MozBoxShadow = 'rgba(0,0,0," + Number(i / frames) / 2 + ") 3px 3px 3px'", i * delay);setTimeout("RGraph.Registry.Get('chart.zoomedimage').style.WebkitBoxShadow = 'rgba(0,0,0," + Number(i / frames) / 2 + ") 3px 3px 3px'", i * delay);}
}
}