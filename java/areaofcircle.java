public class Circle {
    private double radius;

    public Circle() {
        radius = 0;
    }

    public Circle(double radius) {
        this.radius = radius;
    }

    public double getRadius() {
        return radius;
    }

    public void setRadius(double radius) {
        this.radius = radius;
    }

    public double getArea() {
        return calculateArea();
    }

    private double calculateArea() {
        return radius * radius * Math.PI;
    }

    public String toString() {
        return "The radius of the circle is: " + radius + ", and the area is: "
                + calculateArea();
    }
}
