import { combineReducers } from 'redux';
import status from './status';
import app from './app';

export default combineReducers({
    status,
    app,
})