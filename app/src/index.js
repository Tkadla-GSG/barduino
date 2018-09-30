import React from 'react';
import ReactDOM from 'react-dom';
import { compose } from 'lodash/fp';
import { createStore, applyMiddleware } from 'redux';
import { Provider } from 'react-redux';
import thunkMiddleware from 'redux-thunk';
import createSocketMiddleware from 'redux-websocket-bridge';
import { logger } from 'redux-logger';
import App from './App';
import reducers from './reducers';

const websocketMiddleware = createSocketMiddleware((window.config && window.config.websocketEndpoint) || 'ws://echo.websocket.org');
const middlewares = [
    thunkMiddleware,
    websocketMiddleware
];
if (process.env.NODE_ENV === `development`) {
    middlewares.push(logger);
}

const store = compose(applyMiddleware(...middlewares))(createStore)(reducers);
ReactDOM.render(
    <Provider store={store}>
        <App />
    </Provider>,
    document.getElementById('root')
);
