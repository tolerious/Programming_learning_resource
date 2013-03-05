/***
 * Excerpted from "HTML5 and CSS3",
 * published by The Pragmatic Bookshelf.
 * Copyrights apply to this code. It may not be used to create training material, 
 * courses, books, articles, and the like. Contact us if you are in doubt.
 * We make no guarantees that this code is fit for any purpose. 
 * Visit http://www.pragmaticprogrammer.com/titles/bhh5 for more book information.
***/
// Database reference
var db = null;




// Creates a connection to the local database
connectToDB = function()
{
   db = window.openDatabase('awesome_notes', '1.0',
                                   'AwesomeNotes Database', 1024*1024*3);
};



//Create the table method
createNotesTable = function()
{
   db.transaction(function(tx){
      tx.executeSql(
        "CREATE TABLE notes (id INTEGER PRIMARY KEY, title TEXT, note TEXT)", [],
        function(){ alert('Notes database created successfully!'); },
        function(tx, error){ alert(error.message); } );
      });
};

//Insert record into Table.
insertNote = function(title, note)
{
   db.transaction(function(tx){
      tx.executeSql("INSERT INTO notes (title, note) VALUES (?, ?)", 
                     [title.val(), note.val()],
        function(tx, result){ 
         var id = result.insertId ;
         alert('Record ' + id+ 'saved!');
         title.attr("data-id", result.insertId );
         addToNotesList(id, title.val());
         $("#delete_button").show();
         
        },
        function(){ 
          alert('The note could not be saved.'); 
        }
      );
   });
};


/* update record into Table. Takes the Title field and Note field
   which are both jQuery objects. The id to update is a custom data attribute on the title field.
*/

updateNote = function(title, note)
{
   var id = title.attr("data-id");
   db.transaction(function(tx){
    tx.executeSql("UPDATE notes set title = ?, note = ? where id = ?",
                  [title.val(), note.val(), id],
      function(tx, result){ 
        alert('Record ' + id + ' updated!');
        $("#notes>li[data-id=" + id + "]").html(title.val());
      },
      function(){ 
        alert('The note was not updated!');
      }
    );
  });
};


//remove record from Table.
deleteNote = function(title)
{
   var id = title.attr("data-id");
   db.transaction(function(tx){
      tx.executeSql("DELETE from notes where id = ?", [id],
        function(tx, result){ 
         alert('Record ' + id + ' deleted!');
         $("#notes>li[data-id=" + id + "]").remove();
        },
        function(){ 
         alert('The note was not deleted!');
        }
      );
   });
};



// loads all records from the notes table of the database;
fetchNotes = function(){
  db.transaction(function(tx) {
      tx.executeSql('SELECT id, title, note FROM notes', [],
        function(SQLTransaction, data){
          for (var i = 0; i < data.rows.length; ++i) {
              var row = data.rows.item(i);
              var id = row['id'];
              var title = row['title'];

              addToNotesList(id, title);
          }
      });
  });
};

// Adds the list item to the list of notes, given an id and a title.
addToNotesList = function(id, title){
  var notes = $("#notes");
  var item = $("<li>");
  item.attr("data-id", id);
  item.html(title);               
  notes.append(item);
};


// loads a single note from the notes table using the given id
loadNote = function(id){
  db.transaction(function(tx) {
    tx.executeSql('SELECT id, title, note FROM notes where id = ?', [id],
      function(SQLTransaction, data){
        var row = data.rows.item(0);
        var title = $("#title");
        var note = $("#note");

        title.val(row["title"]);
        title.attr("data-id", row["id"]);
        note.val(row["note"]);
        $("#delete_button").show();

      });
  });
}



// Clears out the form and removes the "delete" button
newNote = function(){
  $("#delete_button").hide();
  var title = $("#title");
  title.removeAttr("data-id");
  title.val("");
  var note = $("#note");
  note.val("");
}


$(function(){
  connectToDB();
  createNotesTable();
  fetchNotes();

  
  $("#save_button").click(function(event){
    event.preventDefault();
    var title = $("#title");
    var note = $("#note");
    
    if(title.attr("data-id")){
      updateNote(title, note);
    }else{
      insertNote(title, note);
    }
  });

  
  $("#delete_button").click(function(event){
    event.preventDefault();
    var title = $("#title");
    deleteNote(title);
  });
  
  $("#notes").click(function(event){
    if ($(event.target).is('li')) {
      var element = $(event.target);
      loadNote(element.attr("data-id"));
    }
    
  });
  
  $("#new_button").click(function(event){
    event.preventDefault();
    newNote();
  });
  //end:newbutton
  
  
  newNote();  
  
});

