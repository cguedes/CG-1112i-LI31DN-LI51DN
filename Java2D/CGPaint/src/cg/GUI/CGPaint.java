package cg.GUI;

import cg.GUI.action.*;
import cg.algorithms.circle.CircleAlgorithmChooser;
import cg.algorithms.circle.ICircleAlgorithm;
import cg.algorithms.line.IScanLineAlgorithm;
import cg.algorithms.line.LineAlgorithmChooser;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.Point;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.ComponentEvent;
import java.awt.event.ComponentListener;
import java.awt.event.ItemEvent;
import java.awt.event.ItemListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.MouseMotionAdapter;
import java.util.ArrayList;
import java.util.Dictionary;
import java.util.Enumeration;
import java.util.Hashtable;
import javax.swing.ButtonGroup;
import javax.swing.ImageIcon;
import javax.swing.JApplet;
import javax.swing.JButton;
import javax.swing.JCheckBox;
import javax.swing.JColorChooser;
import javax.swing.JComboBox;
import javax.swing.JDialog;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JToggleButton;
import javax.swing.JToolBar;



public class CGPaint extends JApplet {
	
	private static final long serialVersionUID = 6698963832673229111L;

	
	//para cmd de primitivas
	private static Dictionary<String, IPerformAction> primitives = new Hashtable<String, IPerformAction>();
	static
	{
		primitives.put("circle",   				new DoCircle());
		primitives.put("fillCircle",   			new DoFillCircle());
		primitives.put("line",     				new DoLine());
		primitives.put("rectangle",     		new DoRectangle());
		primitives.put("fillRectangle", 		new DoFillRectangle());
		primitives.put("fillConvexPolygon", 	new DoConvexPolygon());
		primitives.put("fillConcavePolygon", 	new DoConcavePolygon());
		primitives.put("drawRGB",  				new DoDrawRGBTriangle());
	}
	
	// Device Gráfico no qual são desenhados os pixeis 
	/**
	 */
	//private IRasterDevice dc = new GridView(15, 15);
	private IRasterDevice dc = new GridView(50, 50);
	//private IRasterDevice dc = new GridView(400, 300);
	// Componente de status
	/**
	 */
	private JLabel status = new JLabel();
	
	private Color color =  Color.BLUE;

	private IScanLineAlgorithm lineAlgorithm = LineAlgorithmChooser.getDefaultAlgorithm();
	private ICircleAlgorithm circleAlgorithm = CircleAlgorithmChooser.getDefaultAlgorithm();
	private IPerformAction primitive =  getDefaultPrimitive();
	
	/**
	 * Ponto de entrada da aplicação (Applet)
	 */
	public void start() {
		super.start();
		
		this.setSize(new Dimension(800, 600));
		this.setLayout(new BorderLayout());

		addFrameComponents();
		setupFrameEvents();
	}

	/**
	 * Regista os eventos necessários ao funcionamento da aplicação, nomeadamente:
	 *   - dois cliques consecutivos no device gráfico geram uma linha
	 *   - mostrar as coordenadas actuais do mouse
	 *   - clique no botão "Clear" limpa o ecrã
	 */
	private void setupFrameEvents() {

		dc.addClickListener(new MouseAdapter() {
			 
			public void mouseClicked(MouseEvent me) {
				status.setText("outch:" + me.getPoint().toString());
				Color color = getCurrentColor();
				primitive.doAction(CGPaint.this, me.getPoint(), color);
				dc.getComponent().repaint();

			}
		});
		// Mostrar as coordenadas actuais do mouse a barra de estado
		dc.addMotionListener(new MouseMotionAdapter() {
			public void mouseMoved(MouseEvent me) {
				status.setText("(" + me.getX() + ", " + me.getY() + ")");
				primitive.drawAction(CGPaint.this, me.getPoint(), getCurrentColor());
				dc.getComponent().repaint();
			}
			public void mouseDragged(MouseEvent me) {
				//dc.writePixel(me.getX(), me.getY(), Color.ORANGE);
				//dc.getComponent().repaint();
			}
		});
		
		this.addComponentListener( new ComponentListener() {
			public void componentHidden(ComponentEvent e)  { }
			public void componentMoved(ComponentEvent e)   { }
			public void componentResized(ComponentEvent e) { dc.invalidateScreenData(); }
			public void componentShown(ComponentEvent e)   { }
			
		
		});

		
	}
	
	/**
	 * Acrescenta os componentes necessário a esta aplicação, nomeadamente:
	 *   - RadioButtons para escolher o modo de desenho (linha, circulo ou rectangulo)
	 *   - dropDown para escolher o algoritmo a utilizar (linha ou circulo)
	 *   - botão para limpar o ecrã
	 *   - checkBox para indicar se estamos em modo debug
	 *   - botões para aumentar e diminuir o tamanho da grelha do device gráfico
	 *   - DeviceGráfico (implementado à custa do Canvas [GridView])
	 */
	private void addFrameComponents() {
		
		/// Components 
		
		
		JToggleButton cbDrawLine          		= new JToggleButton(new ImageIcon("img//linha.gif"), true);
		JToggleButton cbDrawCircle        		= new JToggleButton(new ImageIcon("img//circulo.gif"), false);
		JToggleButton cbDrawFillCircle		   	= new JToggleButton(new ImageIcon("img//FillCirculo.gif"), false);
		JToggleButton cbDrawFillConvexPolygon  	= new JToggleButton(new ImageIcon("img//PoligonoConvexo.gif"), false);
		JToggleButton cbDrawFillConcavePolygon  = new JToggleButton(new ImageIcon("img//PoligonoConcavo.gif"), false);
		JToggleButton cbDrawRGBTriangle   		= new JToggleButton(new ImageIcon("img//RGB.gif"), false);
		
		ButtonGroup group = new ButtonGroup();
		group.add(cbDrawLine);
		group.add(cbDrawCircle);
		group.add(cbDrawFillCircle);
		group.add(cbDrawFillConvexPolygon);
		group.add(cbDrawFillConcavePolygon);
		group.add(cbDrawRGBTriangle);
		 
		///toolbar
		JToolBar toolbar=new JToolBar(); 
		
		//Adicionar componentes	
		toolbar.add(cbDrawLine);
		toolbar.add(cbDrawCircle);
		toolbar.add(cbDrawFillCircle);
		toolbar.add(cbDrawFillConvexPolygon);
		toolbar.add(cbDrawFillConcavePolygon);
		toolbar.add(cbDrawRGBTriangle);
		toolbar.addSeparator(new Dimension(20,20));
		toolbar.add(new JLabel("Algoritmo:"));
		toolbar.addSeparator();
				
		final JComboBox chAlgorithmLine = new JComboBox();
		final JComboBox chAlgorithmCircle = new JComboBox();
				
		toolbar.add(chAlgorithmLine);
		toolbar.add(chAlgorithmCircle);
		toolbar.addSeparator();
		
		// enable/disable comboBoxes
		cbDrawLine.setEnabled(true);
		cbDrawCircle.setEnabled(true);
		cbDrawFillConvexPolygon.setEnabled(true);
		cbDrawFillConcavePolygon.setEnabled(true);
		cbDrawRGBTriangle.setEnabled(true);
		
		// definir estado inicial dos componentes (JComboBox)
		Enumeration<String> algNamesLines = LineAlgorithmChooser.getAvailableAlgorithms();
		while(algNamesLines.hasMoreElements()) {
			chAlgorithmLine.addItem(algNamesLines.nextElement());			 
		}
		Enumeration<String> algNamesCircles = CircleAlgorithmChooser.getAvailableAlgorithms();
		while(algNamesCircles.hasMoreElements()) {
			chAlgorithmCircle.addItem(algNamesCircles.nextElement());			 
		}
		chAlgorithmLine.setEnabled(true);
		chAlgorithmCircle.setEnabled(false);
		
		// Registo de eventos
		cbDrawLine.addItemListener(new ItemListener() {
			public void itemStateChanged(ItemEvent e) {
				setCurrentPrimitive("line");
				chAlgorithmLine.setEnabled(true);
				chAlgorithmCircle.setEnabled(false);
			}
		});
		cbDrawCircle.addItemListener(new ItemListener() {
			public void itemStateChanged(ItemEvent e) {
				setCurrentPrimitive("circle");
				chAlgorithmLine.setEnabled(false);
				chAlgorithmCircle.setEnabled(true);
			}
		});
		cbDrawFillCircle.addItemListener(new ItemListener() {
			public void itemStateChanged(ItemEvent e) {
				setCurrentPrimitive("fillCircle");
				chAlgorithmLine.setEnabled(false);
				chAlgorithmCircle.setEnabled(false);
			}
		});
		cbDrawFillConvexPolygon.addItemListener(new ItemListener() {
			public void itemStateChanged(ItemEvent e) {
				setCurrentPrimitive("fillConvexPolygon");
				chAlgorithmLine.setEnabled(false);
				chAlgorithmCircle.setEnabled(false);
			}
		});
		cbDrawFillConcavePolygon.addItemListener(new ItemListener() {
			public void itemStateChanged(ItemEvent e) {
				setCurrentPrimitive("fillConcavePolygon");
				chAlgorithmLine.setEnabled(false);
				chAlgorithmCircle.setEnabled(false);
			}
		});
		cbDrawRGBTriangle.addItemListener(new ItemListener() {
			public void itemStateChanged(ItemEvent e) {
				setCurrentPrimitive("drawRGB");
				chAlgorithmLine.setEnabled(false);
				chAlgorithmCircle.setEnabled(false);
			}
		});
		
		chAlgorithmLine.addItemListener(new ItemListener() {
			public void itemStateChanged(ItemEvent e) {
				lineAlgorithm = LineAlgorithmChooser.getAlgorithm((String)chAlgorithmLine.getSelectedItem());
			}
		});
		chAlgorithmCircle.addItemListener(new ItemListener() {
			public void itemStateChanged(ItemEvent e) {
				circleAlgorithm = CircleAlgorithmChooser.getAlgorithm((String)chAlgorithmLine.getSelectedItem());
			}
		});
		
		JButton btnChooseColor = new JButton(new ImageIcon("img//colorChooser.gif"));
		btnChooseColor.addActionListener(new ActionListener() 
		{
			public void actionPerformed(ActionEvent arg0) 
			{
				final JColorChooser chooser = new JColorChooser(color != null ? color :Color.BLUE);
				ActionListener okListener = new ActionListener() {
					public void actionPerformed(ActionEvent ae) {
						color = chooser.getColor();
					}
				};
				JDialog dialog = JColorChooser.createDialog(null, "Color", true, chooser, okListener, null);
				dialog.setVisible(true);
			}
		}	
		);
		toolbar.add(btnChooseColor);
	    final ColorChooser colorChooser = new ColorChooser();
	    color = colorChooser.selectedColor;
	    colorChooser.setActionListener(new ActionListener() {
	      public void actionPerformed(ActionEvent actionEvent) {
	        color = colorChooser.selectedColor;
	      }
	    });
	    toolbar.add( colorChooser );
	    
		/// Debug ----------------------------------------------------------------------------
		JPanel pnlDebug = new JPanel(new FlowLayout(FlowLayout.LEFT));
		dc.setDebugMode(true);
		JCheckBox cbDebugMode = new JCheckBox("Debug", dc.isInDebugMode());
		
		cbDebugMode.addMouseListener(new MouseAdapter() {
			public void mouseClicked(MouseEvent arg0) {
				dc.setDebugMode(!dc.isInDebugMode());
				dc.getComponent().repaint();
			}
		});

		
		JButton btnClear = new JButton(new ImageIcon("img//newDoc.gif"));
		btnClear.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				dc.clear();
				dc.getComponent().repaint();
			}
		});
		JButton btnIncGridSize = new JButton(new ImageIcon("img//zoom-out.gif"));
		btnIncGridSize.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				dc.incGridSize();
				dc.getComponent().repaint();
			}
		});
		JButton btnDecGridSize = new JButton(new ImageIcon("img//zoom-in.gif"));
		btnDecGridSize.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				dc.decGridSize();
				dc.getComponent().repaint();
			}
		});
		pnlDebug.add(cbDebugMode);
		
		pnlDebug.add(btnClear);
		pnlDebug.add(btnIncGridSize);
		pnlDebug.add(btnDecGridSize);
		
		toolbar.add(pnlDebug);		
		
		this.add("North", toolbar);
		this.add("East", new JLabel());
		this.add("West", new JLabel());
		this.add("South", status);
		this.add("Center", dc.getComponent());
		
		
	}
	
	public void drawInfoLines(Point p[], int nPoints){
		dc.drawInfoLines(p, nPoints);
		dc.invalidateScreenData(); 
	}
	
	public void drawInfoCircle(Point c, Point r){
		dc.drawInfoCircle(c,r);
		dc.invalidateScreenData(); 
	}
	
	public void drawInfoRectgangle(Point a, Point b){
		dc.drawInfoRectgangle(a,b);
		dc.invalidateScreenData(); 
	}
	
	public void clearInfo(){
		dc.clearInfo();
		dc.invalidateScreenData(); 
	}
	
	public ICircleAlgorithm getCurrentCircleAlgorithm(){return circleAlgorithm;}
	public IScanLineAlgorithm getCurrentLineAlgorithm(){return lineAlgorithm;}
	public IRasterDevice getRasterDisplay(){return dc;}
	public Color getCurrentColor(){return color;} 
	
	public IPerformAction getDefaultPrimitive(){return primitives.get("line");}
	public void setCurrentPrimitive(String name){primitive = primitives.get(name);}
	public IPerformAction getCurrentPrimitive(String name){return primitives.get(name);}
}
