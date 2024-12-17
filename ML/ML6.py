import tensorflow as tf
from tensorflow.keras import layers, models
from tensorflow.keras.models import Sequential
from tensorflow.keras.datasets import mnist
from tensorflow.keras.utils import to_categorical

(X_train, y_train), (X_test, y_test) = mnist.load_data()
print('Train: X = %s, y = %s' % (X_train.shape, y_train.shape))
print('Test : X = %s, y = %s' % (X_test.shape, y_test.shape))
print('X_train.shape[0]: X=%s' % X_train.shape[0])
X_train = X_train.reshape((X_train.shape[0], -1)) / 255.0
X_test = X_test.reshape((X_test.shape[0], -1)) / 255.0
y_train = to_categorical(y_train)
y_test = to_categorical(y_test)
# relu
model_simple = Sequential([
layers.Flatten(input_shape=(784,)),
layers.Dense(10, activation='softmax')
])
print(' simple_model 1')
model_simple.compile(optimizer='adam', loss='categorical_crossentropy', metrics=['accuracy'])
#model_simple.compile(optimizer='adam', loss='binary_crossentropy', metrics=['accuracy'])
model_simple.fit(X_train, y_train, epochs=5, batch_size=32, validation_data=(X_test, y_test))
hidden_layer_model = models.Sequential([
layers.Flatten(input_shape=(784,)),
layers.Dense(128, activation='relu'),
layers.Dense(10, activation='softmax')
])

print(' hidden_layer_model with relu function')
hidden_layer_model.compile(optimizer='adam', loss='categorical_crossentropy',
metrics=['accuracy'])
hidden_layer_model.fit(X_train, y_train, epochs=5, batch_size=32, validation_data=(X_test,
y_test))
# sigmoid
model_simple = Sequential([
layers.Flatten(input_shape=(784,)),
layers.Dense(10, activation='softmax')
])
print(' simple_model 2')
model_simple.compile(optimizer='adam', loss='categorical_crossentropy', metrics=['accuracy'])
#model_simple.compile(optimizer='adam', loss='binary_crossentropy', metrics=['accuracy'])
model_simple.fit(X_train, y_train, epochs=5, batch_size=32, validation_data=(X_test, y_test))
hidden_layer_model = models.Sequential([
layers.Flatten(input_shape=(784,)),
layers.Dense(128, activation='sigmoid'),
layers.Dense(10, activation='softmax')
])
print(' hidden_layer_model with sigmoid function')
hidden_layer_model.compile(optimizer='adam', loss='categorical_crossentropy',
metrics=['accuracy'])
hidden_layer_model.fit(X_train, y_train, epochs=5, batch_size=32, validation_data=(X_test,
y_test))
# tanh
model_simple = Sequential([
layers.Flatten(input_shape=(784,)),
layers.Dense(10, activation='softmax')
])
print(' simple_model 3')
model_simple.compile(optimizer='adam', loss='categorical_crossentropy', metrics=['accuracy'])
#model_simple.compile(optimizer='adam', loss='binary_crossentropy', metrics=['accuracy'])
model_simple.fit(X_train, y_train, epochs=5, batch_size=32, validation_data=(X_test, y_test))
hidden_layer_model = models.Sequential([
layers.Flatten(input_shape=(784,)),
layers.Dense(128, activation='tanh'),
layers.Dense(10, activation='softmax')])

print(' hidden_layer_model with tanh function')
hidden_layer_model.compile(optimizer='adam', loss='categorical_crossentropy',
metrics=['accuracy'])
hidden_layer_model.fit(X_train, y_train, epochs=5, batch_size=32, validation_data=(X_test,
y_test))
