REM for %%F in (*.bcs) do %bcc% "%%~nF.bcs" "..\pk3\acs\%%~nF.lmp"

%bcc% "dnd.bcs" "..\dnd\acs\dnd.lmp"
%bcc% "dnd_database.bcs" "..\dnd\acs\dnd_db.lmp"
%bcc% "dnd_menu.bcs" "..\dnd\acs\dnd_menu.lmp"
%bcc% "dnd_shared.bcs" "..\dnd\acs\dnd_shrd.lmp"
%bcc% "dnd_mons.bcs" "..\monsters\acs\dnd_mons.lmp"