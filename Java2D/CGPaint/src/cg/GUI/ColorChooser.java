/*
 * ColorChooser.java
 *
 * Created on 12 de Outubro de 2007, 16:29
 */

package cg.GUI;

import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.lang.reflect.Field;
import javax.swing.*;
import javax.swing.border.Border;

/**
 *
 * @author  cguedes
 */
public class ColorChooser extends javax.swing.JPanel {
  
  /** Creates new form ColorChooser */
  public ColorChooser() {
    initComponents();
    
    cbColors.setRenderer( new ListCellRenderer() {
      public Component getListCellRendererComponent(JList list, Object value, int index, boolean isSelected, boolean cellHasFocus) {
        
        String colorName = value.toString().toLowerCase();
        final Color color = getColor(colorName);
        
        JPanel pnlColor = new JPanel() {
          public void paint(Graphics g) {
            g.setColor(color);
            g.fillRect(0,0, getWidth(), getHeight());
          }
        };
        
        pnlColor.setBackground(color);
        pnlColor.setPreferredSize( new Dimension(40, 20) );
        
        return pnlColor;
      };
    }
    );
    
  }
  // Returns a Color based on 'colorName' which must be one of the predefined colors in
  // java.awt.Color. Returns null if colorName is not valid.
  public Color getColor(String colorName) {
    try {
      // Find the field and value of colorName
      Field field = Class.forName("java.awt.Color").getField(colorName);
      return (Color)field.get(null);
    } catch (Exception e) {
      return null;
    }
  }
  
  
  public Color selectedColor = Color.RED;
  
  
  /** This method is called from within the constructor to
   * initialize the form.
   * WARNING: Do NOT modify this code. The content of this method is
   * always regenerated by the Form Editor.
   */
  // <editor-fold defaultstate="collapsed" desc=" Generated Code ">//GEN-BEGIN:initComponents
  private void initComponents() {
    cbColors = new javax.swing.JComboBox();

    setLayout(new java.awt.BorderLayout());

    cbColors.setModel(new javax.swing.DefaultComboBoxModel(new String[] { "Red", "Green", "Blue", "Cyan", "Magenta", "Yellow" }));
    cbColors.addActionListener(new java.awt.event.ActionListener() {
      public void actionPerformed(java.awt.event.ActionEvent evt) {
        cbColorsActionPerformed(evt);
      }
    });

    add(cbColors, java.awt.BorderLayout.CENTER);

  }// </editor-fold>//GEN-END:initComponents
  
  private void cbColorsActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_cbColorsActionPerformed
	selectedColor = getColor( cbColors.getSelectedItem().toString().toLowerCase() );
    evt.setSource( selectedColor );
    if(actionPerformed != null)
      actionPerformed.actionPerformed(evt);
  }//GEN-LAST:event_cbColorsActionPerformed
  
  private ActionListener actionPerformed = null;
  public void setActionListener(ActionListener actionList) {
    actionPerformed = actionList;
  }
  
  
  // Variables declaration - do not modify//GEN-BEGIN:variables
  private javax.swing.JComboBox cbColors;
  // End of variables declaration//GEN-END:variables
  
}
