/* =========================================================
 * ====                   WARNING                        ===
 * =========================================================
 * The code in this tab has been generated from the GUI form
 * designer and care should be taken when editing this file.
 * Only add/edit code inside the event handlers i.e. only
 * use lines between the matching comment tags. e.g.

 void myBtnEvents(GButton button) { //_CODE_:button1:12356:
     // It is safe to enter your event code here  
 } //_CODE_:button1:12356:
 
 * Do not rename this tab!
 * =========================================================
 */

public void consola_change(GTextField source, GEvent event) { //_CODE_:consola:321194:
  println("consola - GTextField event occured " + System.currentTimeMillis()%10000000 );
} //_CODE_:consola:321194:

public void knob1_turn1(GKnob source, GEvent event) { //_CODE_:knob1:825983:
  println("knob1 - GKnob event occured " + System.currentTimeMillis()%10000000 );
} //_CODE_:knob1:825983:

// Create all the GUI controls. 
// autogenerated do not edit
public void createGUI(){
  G4P.messagesEnabled(false);
  G4P.setGlobalColorScheme(GCScheme.BLUE_SCHEME);
  G4P.setCursor(ARROW);
  if(frame != null)
    frame.setTitle("Sketch Window");
  consola = new GTextField(this, 20, 26, 389, 117, G4P.SCROLLBARS_NONE);
  consola.setOpaque(true);
  consola.addEventHandler(this, "consola_change");
  knob1 = new GKnob(this, 225, 220, 60, 60, 0.8);
  knob1.setTurnRange(110, 70);
  knob1.setTurnMode(GKnob.CTRL_HORIZONTAL);
  knob1.setSensitivity(1);
  knob1.setShowArcOnly(false);
  knob1.setOverArcOnly(false);
  knob1.setIncludeOverBezel(false);
  knob1.setShowTrack(true);
  knob1.setLimits(0.5, 0.0, 1.0);
  knob1.setShowTicks(true);
  knob1.setOpaque(false);
  knob1.addEventHandler(this, "knob1_turn1");
}

// Variable declarations 
// autogenerated do not edit
GTextField consola; 
GKnob knob1; 

