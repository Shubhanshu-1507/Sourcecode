import numpy as np
import pandas as pd
from sklearn.preprocessing import MinMaxScaler
from sklearn.model_selection import train_test_split
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import LSTM, Dense
from tensorflow.keras.optimizers import Adam

# Generate some sample data
np.random.seed(42)
dates = pd.date_range(start='2020-01-01', end='2023-12-31', freq='D')
prices = np.random.randint(50, 150, size=len(dates)) + np.sin(np.arange(len(dates)) * 2 * np.pi / 365) * 20
df = pd.DataFrame({'date': dates, 'price': prices})

# Prepare the data
scaler = MinMaxScaler(feature_range=(0, 1))
scaled_prices = scaler.fit_transform(df['price'].values.reshape(-1, 1))

def create_sequences(data, seq_length):
    sequences = []
    targets = []
    for i in range(len(data) - seq_length):
        seq = data[i:i+seq_length]
        target = data[i+seq_length]
        sequences.append(seq)
        targets.append(target)
    return np.array(sequences), np.array(targets)

# Create sequences with 3 months (90 days) of historical data
seq_length = 90
X, y = create_sequences(scaled_prices, seq_length)

# Split the data into training and testing sets
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

# Build the LSTM model
model = Sequential([
    LSTM(50, activation='relu', input_shape=(seq_length, 1), return_sequences=True),
    LSTM(50, activation='relu'),
    Dense(1)
])

model.compile(optimizer=Adam(learning_rate=0.001), loss='mse')

# Train the model
history = model.fit(X_train, y_train, epochs=50, batch_size=32, validation_split=0.1, verbose=1)

# Evaluate the model
loss = model.evaluate(X_test, y_test, verbose=0)
print(f'Test loss: {loss}')

# Function to predict the next day's price
def predict_next_price(model, last_90_days):
    last_90_days_scaled = scaler.transform(last_90_days.reshape(-1, 1))
    X = last_90_days_scaled.reshape(1, seq_length, 1)
    predicted_price_scaled = model.predict(X)
    predicted_price = scaler.inverse_transform(predicted_price_scaled)
    return predicted_price[0][0]

# Example usage
last_90_days = df['price'].values[-90:]
predicted_price = predict_next_price(model, last_90_days)
print(f'Predicted price for the next day: ${predicted_price:.2f}')

# Plot actual vs predicted prices for the test set
import matplotlib.pyplot as plt

y_pred = model.predict(X_test)
y_test_inv = scaler.inverse_transform(y_test)
y_pred_inv = scaler.inverse_transform(y_pred)

plt.figure(figsize=(10, 6))
plt.plot(y_test_inv, label='Actual Prices')
plt.plot(y_pred_inv, label='Predicted Prices')
plt.title('Actual vs Predicted Vegetable Prices')
plt.xlabel('Time')
plt.ylabel('Price')
plt.legend()
plt.show()
