import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.TextField;
import javafx.scene.layout.HBox;
import javafx.scene.layout.Pane;
import javafx.scene.layout.VBox;
import javafx.scene.paint.Color;
import javafx.scene.shape.Circle;
import javafx.scene.text.Font;
import javafx.scene.text.Text;
import javafx.stage.Stage;

public class SpinningWheel extends Application {

    public static void main(String[] args) {
        launch(args);
    }

    private Circle circle;
    private Pane root;
    private TextField text;
    private Button button;

    @Override
    public void start(Stage primaryStage) {

        root = new Pane();

        Text lable = new Text("Item Name: ");
        lable.setFont(Font.font("Arial",12));

        text = new TextField("");
        text.setPrefWidth(200);

        HBox hbox = new HBox(20);
        hbox.getChildren().addAll(lable, text);
        hbox.setPadding(new Insets(20));

        button = new Button("Add Item");
        VBox vbox = new VBox(20);
        vbox.getChildren().addAll(hbox,button);
        vbox.setAlignment(Pos.CENTER);

        circle = new Circle(200,200,150,Color.TRANSPARENT);
        circle.setStroke(Color.BLACK);
        Circle circle2 = new Circle(200,200,2, Color.BLACK);
        root.getChildren().addAll(circle,circle2);

        HBox total = new HBox(vbox, root);


        Scene scene = new Scene(total, 800, 400);
        primaryStage.setTitle("Spinning Wheel");
        primaryStage.setScene(scene);
        primaryStage.show();

    }

    private class Adder implements EventHandler<ActionEvent> {

        @Override
        public void handle(ActionEvent event) {
            double radius = circle.getRadius();

        }
    }

}


