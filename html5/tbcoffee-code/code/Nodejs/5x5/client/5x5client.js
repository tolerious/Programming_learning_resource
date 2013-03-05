/***
 * Excerpted from "CoffeeScript",
 * published by The Pragmatic Bookshelf.
 * Copyrights apply to this code. It may not be used to create training material, 
 * courses, books, articles, and the like. Contact us if you are in doubt.
 * We make no guarantees that this code is fit for any purpose. 
 * Visit http://www.pragmaticprogrammer.com/titles/tbcoffee for more book information.
***/
/***
 * Excerpted from "CoffeeScript",
 * published by The Pragmatic Bookshelf.
 * Copyrights apply to this code. It may not be used to create training material, 
 * courses, books, articles, and the like. Contact us if you are in doubt.
 * We make no guarantees that this code is fit for any purpose. 
 * Visit http://www.pragmaticprogrammer.com/titles/tbcoffee for more book information.
***/
(function() {
  var drawTiles, endTurn, handleMessage, myNum, myTurn, selectedCoordinates, showMessage, showMoveResult, showThenFade, socket, startGame, startTurn, swapTiles, tileClick, tiles, typeAndContent;
  socket = tiles = selectedCoordinates = myNum = myTurn = null;
  startTurn = function() {
    myTurn = true;
    return showMessage('firstTile');
  };
  endTurn = function() {
    selectedCoordinates = null;
    myTurn = false;
    return showMessage('waitForMove');
  };
  drawTiles = function() {
    var gridHtml, x, y, _ref, _ref2;
    gridHtml = '';
    for (x = 0, _ref = tiles.length; (0 <= _ref ? x < _ref : x > _ref); (0 <= _ref ? x += 1 : x -= 1)) {
      gridHtml += '<ul>';
      for (y = 0, _ref2 = tiles.length; (0 <= _ref2 ? y < _ref2 : y > _ref2); (0 <= _ref2 ? y += 1 : y -= 1)) {
        gridHtml += "<li id='tile" + x + "_" + y + "'>" + tiles[x][y] + "</li>";
      }
      gridHtml += '</ul>';
    }
    return $('#grid').html(gridHtml);
  };
  showMessage = function(messageType) {
    var messageHtml;
    switch (messageType) {
      case 'waitForConnection':
        messageHtml = "Waiting for another player to connect to the server...";
        break;
      case 'waitForMove':
        messageHtml = "Waiting for the other player to make a move...";
        break;
      case 'firstTile':
        messageHtml = "Please select your first tile.";
        break;
      case 'secondTile':
        messageHtml = "Please select a second tile.";
    }
    return $('#message').html(messageHtml);
  };
  showThenFade = function($elem) {
    var animationTarget;
    $elem.insertAfter($('#grid'));
    animationTarget = {
      opacity: 0,
      height: 0,
      padding: 0
    };
    return $elem.delay(5000).animate(animationTarget, 500, function() {
      return $elem.remove();
    });
  };
  tileClick = function() {
    var $this, x, y, _ref;
    if (!myTurn) {
      return;
    }
    $this = $(this);
    if ($this.hasClass('selected')) {
      selectedCoordinates = null;
      $this.removeClass('selected');
      return showMessage('firstTile');
    } else {
      _ref = this.id.match(/(\d+)_(\d+)/).slice(1), x = _ref[0], y = _ref[1];
      if (selectedCoordinates === null) {
        selectedCoordinates = {
          x1: x,
          y1: y
        };
        $this.addClass('selected');
        return showMessage('secondTile');
      } else {
        selectedCoordinates.x2 = x;
        selectedCoordinates.y2 = y;
        socket.send("move:" + (JSON.stringify(selectedCoordinates)));
        return endTurn();
      }
    }
  };
  swapTiles = function(_arg) {
    var x1, x2, y1, y2, _ref;
    x1 = _arg.x1, y1 = _arg.y1, x2 = _arg.x2, y2 = _arg.y2;
    _ref = [tiles[x2][y2], tiles[x1][y1]], tiles[x1][y1] = _ref[0], tiles[x2][y2] = _ref[1];
    return drawTiles();
  };
  typeAndContent = function(message) {
    var content, ignore, type, _ref;
    _ref = message.match(/(.*?):(.*)/), ignore = _ref[0], type = _ref[1], content = _ref[2];
    return {
      type: type,
      content: content
    };
  };
  handleMessage = function(message) {
    var content, currPlayerNum, moveScore, newWords, player, players, swapCoordinates, type, _ref, _ref2, _ref3;
    _ref = typeAndContent(message), type = _ref.type, content = _ref.content;
    switch (type) {
      case 'welcome':
        _ref2 = JSON.parse(content), players = _ref2.players, currPlayerNum = _ref2.currPlayerNum, tiles = _ref2.tiles, myNum = _ref2.yourNum;
        return startGame(players, currPlayerNum);
      case 'moveResult':
        _ref3 = JSON.parse(content), player = _ref3.player, swapCoordinates = _ref3.swapCoordinates, moveScore = _ref3.moveScore, newWords = _ref3.newWords;
        return showMoveResult(player, swapCoordinates, moveScore, newWords);
    }
  };
  startGame = function(players, currPlayerNum) {
    var player, _i, _len;
    for (_i = 0, _len = players.length; _i < _len; _i++) {
      player = players[_i];
      $("#p" + player.num + "name").html(player.name);
      $("#p" + player.num + "score").html(player.score);
    }
    drawTiles();
    if (myNum === currPlayerNum) {
      return startTurn();
    } else {
      return endTurn();
    }
  };
  showMoveResult = function(player, swapCoordinates, moveScore, newWords) {
    var $notice;
    $("#p" + player.num + "score").html(player.score);
    $notice = $('<p class="notice"></p>');
    if (moveScore === 0) {
      $notice.html("" + player.name + " formed no words this turn.");
    } else {
      $notice.html("" + player.name + " formed the following " + newWords.length + " word(s):<br />\n<b>" + (newWords.join(', ')) + "</b><br />\nearning <b>" + (moveScore / newWords.length) + "x" + newWords.length + " = " + moveScore + "</b> points!");
    }
    showThenFade($notice);
    swapTiles(swapCoordinates);
    if (player.num !== myNum) {
      return startTurn();
    }
  };
  $(document).ready(function() {
    $('#grid li').live('click', tileClick);
    socket = new io.Socket();
    socket.connect();
    socket.on('connect', function() {
      return showMessage('waitForConnection');
    });
    return socket.on('message', handleMessage);
  });
}).call(this);
